#ifndef RISCV_SYSTEM_INTERFACE_RAM_H_
#define RISCV_SYSTEM_INTERFACE_RAM_H_

#include "riscv/support/primitive_bufs.h"
#include "riscv/system_interface/mmio_device.h"

enum { RAM_SIZE = 1024 * 1024 * 4 };

typedef struct RamDevice {
    MmioDevice super;
    UInt32Buf ram;
} RamDevice;

void ram_device_init(RamDevice* device);
void ram_device_free(RamDevice device);

#endif  // RISCV_SYSTEM_INTERFACE_RAM_H_
