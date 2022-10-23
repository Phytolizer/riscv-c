#include "riscv/system_interface/system_interface.h"

#include <assert.h>

#include "riscv/support/container_of.h"
#include "riscv/support/masks.h"
#include "riscv/system_interface/memory_map.h"

static uint32_t system_interface_read(MmioDevice* device, uint32_t address);
static void system_interface_write(MmioDevice* device, uint32_t address, uint32_t value);

static const MmioDeviceOps ops = {
    .read = system_interface_read,
    .write = system_interface_write,
};

void system_interface_init(SystemInterface* iface, RomDevice* rom, RamDevice* ram) {
    iface->super.ops = &ops;
    iface->super.cb_arg = iface;
    iface->rom = rom;
    iface->ram = ram;
}

static uint32_t system_interface_read(MmioDevice* device, uint32_t address) {
    const SystemInterface* iface = CONTAINER_OF(device, SystemInterface, super);
    assert((address & 0x3) == 0 && "Unaligned memory access");
    if (MASKS(address, MEMORY_MAP_PROGRAM_ROM_START)) {
        return mmio_device_read(
            &iface->rom->super,
            (address & (MEMORY_MAP_PROGRAM_ROM_START - 1)) / sizeof(uint32_t)
        );
    }
    if (MASKS(address, MEMORY_MAP_RAM_START)) {
        return mmio_device_read(
            &iface->ram->super,
            (address & (MEMORY_MAP_PROGRAM_ROM_START - 1)) / sizeof(uint32_t)
        );
    }
    return 0;
}

static void system_interface_write(MmioDevice* device, uint32_t address, uint32_t value) {
    const SystemInterface* iface = CONTAINER_OF(device, SystemInterface, super);
    assert((address & 0x3) == 0 && "Unaligned memory access");
    if (MASKS(address, MEMORY_MAP_RAM_START)) {
        mmio_device_write(
            &iface->ram->super,
            (address & (MEMORY_MAP_PROGRAM_ROM_START - 1)) / sizeof(uint32_t),
            value
        );
    }
}
