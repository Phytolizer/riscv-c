#ifndef RISCV_SYSTEM_INTERFACE_RAM_H_
#define RISCV_SYSTEM_INTERFACE_RAM_H_

#include "riscv/support/primitive_bufs.h"
#include "riscv/system_interface/mmio_device.h"

enum { RAM_SIZE = 1024 * 1024 * 4 };

typedef struct RAMDevice {
    MMIODevice super;
    UInt32Buf ram;
} RAMDevice;

void ram_device_init(RAMDevice* device);
void ram_device_free(RAMDevice device);

#endif  // RISCV_SYSTEM_INTERFACE_RAM_H_
