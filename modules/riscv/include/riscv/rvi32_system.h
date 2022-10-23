#ifndef RISCV_RVI32_SYSTEM_H_
#define RISCV_RVI32_SYSTEM_H_

#include "riscv/pipeline/instruction_decode.h"
#include "riscv/pipeline/instruction_fetch.h"
#include "riscv/state.h"
#include "riscv/system_interface/ram_device.h"
#include "riscv/system_interface/rom_device.h"
#include "riscv/system_interface/system_interface.h"

typedef struct RVI32System {
    State state;
    ROMDevice rom;
    RAMDevice ram;
    SystemInterface bus;
    InstructionFetch ifetch;
    InstructionDecode idecode;
} RVI32System;

void rvi32_system_init(RVI32System* system);
void rvi32_system_free(RVI32System system);

void rvi32_system_compute(RVI32System* system);
void rvi32_system_latch_next(RVI32System* system);
void rvi32_system_cycle(RVI32System* system);

#endif  // RISCV_RVI32_SYSTEM_H_
