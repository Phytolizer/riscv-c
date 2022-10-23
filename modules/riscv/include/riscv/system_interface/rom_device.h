#ifndef RISCV_SYSTEM_INTERFACE_ROM_DEVICE_H_
#define RISCV_SYSTEM_INTERFACE_ROM_DEVICE_H_

#include "riscv/support/primitive_bufs.h"
#include "riscv/system_interface/mmio_device.h"

enum { ROM_SIZE = 1024 * 1024 };

typedef struct RomDevice {
    MmioDevice super;
    UInt32Buf rom;
} RomDevice;

void rom_device_init(RomDevice* device);
void rom_device_free(RomDevice device);

void rom_device_load(RomDevice* device, UInt32Buf data);

#endif  // RISCV_SYSTEM_INTERFACE_ROM_DEVICE_H_
