#ifndef RISCV_SYSTEM_INTERFACE_ROM_DEVICE_H_
#define RISCV_SYSTEM_INTERFACE_ROM_DEVICE_H_

#include "riscv/support/primitive_bufs.h"
#include "riscv/system_interface/mmio_device.h"

enum { ROM_SIZE = 1024 * 1024 };

typedef struct ROMDevice {
    MMIODevice super;
    UInt32Buf rom;
} ROMDevice;

void rom_device_init(ROMDevice* device);
void rom_device_free(ROMDevice device);

void rom_device_load(ROMDevice* device, UInt32Buf data);

#endif  // RISCV_SYSTEM_INTERFACE_ROM_DEVICE_H_
