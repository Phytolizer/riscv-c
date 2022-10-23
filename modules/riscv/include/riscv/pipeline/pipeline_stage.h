#ifndef RISCV_PIPELINE_PIPELINE_STAGE_H_
#define RISCV_PIPELINE_PIPELINE_STAGE_H_

#include <stdbool.h>

typedef struct PipelineStage PipelineStage;

typedef bool PipelineStageReadyToSend(PipelineStage* stage);
typedef bool PipelineStageReadyToReceive(PipelineStage* stage);
typedef void PipelineStageCompute(PipelineStage* stage);
typedef void PipelineStageLatchNext(PipelineStage* stage);

typedef struct PipelineStageOps {
    PipelineStageCompute* compute;
    PipelineStageLatchNext* latch_next;
} PipelineStageOps;

struct PipelineStage {
    const PipelineStageOps* ops;
    void* cb_arg;
};

void pipeline_stage_compute(PipelineStage* stage);
void pipeline_stage_latch_next(PipelineStage* stage);

#endif  // RISCV_PIPELINE_PIPELINE_STAGE_H_
