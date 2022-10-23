#include "riscv/pipeline/execute.h"

static void execute_compute(PipelineStage* arg);
static void execute_latch_next(PipelineStage* arg);

static PipelineStageOps ops = {
    .compute = execute_compute,
    .latch_next = execute_latch_next,
};

void execute_init(Execute* execute, ExecuteParams params) {
    execute->super.ops = &ops;
    execute->super.cb_arg = execute;
    execute->should_stall = params.should_stall;
    execute->get_decoded_values_in = params.get_decoded_values_in;
}

static void execute_compute(PipelineStage* arg) {
    Execute* execute = arg->cb_arg;
    if (!execute->should_stall.cb(execute->should_stall.arg)) {
        DecodedValues decoded =
            execute->get_decoded_values_in.cb(execute->get_decoded_values_in.arg);
    }
}

static void execute_latch_next(PipelineStage* arg) {}
