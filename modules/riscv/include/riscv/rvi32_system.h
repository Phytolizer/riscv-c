#ifndef RISCV_RVI32_SYSTEM_H_
#define RISCV_RVI32_SYSTEM_H_

#include "riscv/pipeline/instruction_decode.h"
#include "riscv/pipeline/instruction_fetch.h"
#include "riscv/state.h"
#include "riscv/system_interface/ram_device.h"
#include "riscv/system_interface/rom_device.h"
#include "riscv/system_interface/system_interface.h"

typedef struct Rvi32System {
    State state;
    RomDevice rom;
    RamDevice ram;
    SystemInterface bus;
    InstructionFetch ifetch;
    InstructionDecode idecode;
} Rvi32System;

void rvi32_system_init(Rvi32System* system);
void rvi32_system_free(Rvi32System system);

void rvi32_system_compute(Rvi32System* system);
void rvi32_system_latch_next(Rvi32System* system);
void rvi32_system_cycle(Rvi32System* system);

#endif  // RISCV_RVI32_SYSTEM_H_
