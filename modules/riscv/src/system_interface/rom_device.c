#include "riscv/system_interface/rom_device.h"

#include "riscv/support/container_of.h"

static uint32_t rom_device_read(MMIODevice* device, uint32_t address);
static void rom_device_write(MMIODevice* device, uint32_t address, uint32_t value);

static const MMIODeviceOps ops = {
    .read = rom_device_read,
    .write = rom_device_write,
};

void rom_device_init(ROMDevice* device) {
    device->super.ops = &ops;
    device->super.cb_arg = device;
    uint32_t* rom = calloc(ROM_SIZE, 1);
    device->rom = (UInt32Buf)BUF_OWNER(rom, ROM_SIZE / sizeof(uint32_t));
}

void rom_device_free(ROMDevice device) {
    BUF_FREE(device.rom);
}

void rom_device_load(ROMDevice* device, UInt32Buf data) {
    for (uint64_t i = 0; i < ROM_SIZE / sizeof(uint32_t); i++) {
        if (i >= data.len) {
            device->rom.ptr[i] = UINT32_C(0xFFFFFFFF);
        } else {
            device->rom.ptr[i] = data.ptr[i];
        }
    }
}

static uint32_t rom_device_read(MMIODevice* device, uint32_t address) {
    ROMDevice* rom = CONTAINER_OF(device, ROMDevice, super);
    return rom->rom.ptr[(size_t)address % (ROM_SIZE / sizeof(uint32_t))];
}

static void rom_device_write(MMIODevice* device, uint32_t address, uint32_t value) {
    // ROM is read-only
    (void)device;
    (void)address;
    (void)value;
}
