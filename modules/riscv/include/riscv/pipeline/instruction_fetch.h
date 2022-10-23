#ifndef RISCV_PIPELINE_INSTRUCTION_FETCH_H_
#define RISCV_PIPELINE_INSTRUCTION_FETCH_H_

#include <stdint.h>

#include "riscv/pipeline/pipeline_stage.h"
#include "riscv/register32.h"
#include "riscv/system_interface/system_interface.h"

typedef bool InstructionFetchShouldStallCallback(void* arg);
typedef struct InstructionFetchShouldStall {
    InstructionFetchShouldStallCallback* cb;
    void* arg;
} InstructionFetchShouldStall;

typedef struct InstructionFetch {
    PipelineStage super;

    Register32 pc;
    Register32 pc_next;
    Register32 instruction;
    Register32 instruction_next;
    SystemInterface* bus;
    InstructionFetchShouldStall should_stall;
} InstructionFetch;

typedef struct InstructionFetchParams {
    SystemInterface* bus;
    InstructionFetchShouldStall should_stall;
} InstructionFetchParams;

void instruction_fetch_init(InstructionFetch* fetch, InstructionFetchParams params);
uint32_t instruction_fetch_get_instruction_out(InstructionFetch* fetch);

#endif  // RISCV_PIPELINE_INSTRUCTION_FETCH_H_
