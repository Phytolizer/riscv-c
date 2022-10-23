#include "riscv/system_interface/ram_device.h"

#include "riscv/support/container_of.h"

static uint32_t ram_device_read(MMIODevice* device, uint32_t address);
static void ram_device_write(MMIODevice* device, uint32_t address, uint32_t value);

static const MMIODeviceOps ops = {
    .read = ram_device_read,
    .write = ram_device_write,
};

void ram_device_init(RAMDevice* device) {
    device->super.ops = &ops;
    device->super.cb_arg = device;
    uint32_t* ram = malloc(RAM_SIZE);
    device->ram = (UInt32Buf)BUF_OWNER(ram, RAM_SIZE / sizeof(uint32_t));
}

void ram_device_free(const RAMDevice device) {
    BUF_FREE(device.ram);
}

static uint32_t ram_device_read(MMIODevice* device, const uint32_t address) {
    const RAMDevice* ram = CONTAINER_OF(device, RAMDevice, super);
    return ram->ram.ptr[(size_t)address % (RAM_SIZE / sizeof(uint32_t))];
}

static void ram_device_write(MMIODevice* device, const uint32_t address, const uint32_t value) {
    const RAMDevice* ram = CONTAINER_OF(device, RAMDevice, super);
    ram->ram.ptr[(size_t)address % (RAM_SIZE / sizeof(uint32_t))] = value;
}
