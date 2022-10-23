#include "riscv/pipeline/instruction_fetch.h"

#include "riscv/support/container_of.h"
#include "riscv/system_interface/memory_map.h"

static void instruction_fetch_compute(PipelineStage* stage);
static void instruction_fetch_latch_next(PipelineStage* stage);

const PipelineStageOps ops = {
    .compute = instruction_fetch_compute,
    .latch_next = instruction_fetch_latch_next,
};

void instruction_fetch_init(InstructionFetch* fetch, InstructionFetchParams params) {
    fetch->super.ops = &ops;
    fetch->super.cb_arg = fetch;
    fetch->pc.value = MEMORY_MAP_PROGRAM_ROM_START;
    fetch->pc_next.value = MEMORY_MAP_PROGRAM_ROM_START;
    fetch->instruction.value = 0;
    fetch->instruction_next.value = 0;
    fetch->bus = params.bus;
    fetch->should_stall = params.should_stall;
}

uint32_t instruction_fetch_get_instruction_out(InstructionFetch* fetch) {
    return fetch->instruction.value;
}

static void instruction_fetch_compute(PipelineStage* stage) {
    InstructionFetch* fetch = CONTAINER_OF(stage, InstructionFetch, super);
    if (!fetch->should_stall.cb(fetch->should_stall.arg)) {
        fetch->instruction_next.value = mmio_device_read(&fetch->bus->super, fetch->pc.value);
        fetch->pc_next.value += sizeof(uint32_t);
    }
}

static void instruction_fetch_latch_next(PipelineStage* stage) {
    InstructionFetch* fetch = CONTAINER_OF(stage, InstructionFetch, super);
    fetch->instruction.value = fetch->instruction_next.value;
    fetch->pc.value = fetch->pc_next.value;
}
