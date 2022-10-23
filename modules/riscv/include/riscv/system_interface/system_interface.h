#ifndef RISCV_SYSTEM_INTERFACE_SYSTEM_INTERFACE_H_
#define RISCV_SYSTEM_INTERFACE_SYSTEM_INTERFACE_H_

#include <stdint.h>

#include "riscv/system_interface/mmio_device.h"
#include "riscv/system_interface/ram_device.h"
#include "riscv/system_interface/rom_device.h"

typedef struct SystemInterface {
    MMIODevice super;
    ROMDevice* rom;
    RAMDevice* ram;
} SystemInterface;

void system_interface_init(SystemInterface* iface, ROMDevice* rom, RAMDevice* ram);

#endif  // RISCV_SYSTEM_INTERFACE_SYSTEM_INTERFACE_H_
