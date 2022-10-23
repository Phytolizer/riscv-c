#include "riscv/system_interface/mmio_device.h"

uint32_t mmio_device_read(MMIODevice* device, const uint32_t address) {
    return device->ops->read(device, address);
}

void mmio_device_write(MMIODevice* device, const uint32_t address, const uint32_t value) {
    device->ops->write(device, address, value);
}
