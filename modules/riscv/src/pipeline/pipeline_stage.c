#include "riscv/pipeline/pipeline_stage.h"

void pipeline_stage_compute(PipelineStage* stage) {
    stage->ops->compute(stage);
}

void pipeline_stage_latch_next(PipelineStage* stage) {
    stage->ops->latch_next(stage);
}
