#ifndef RISCV_PIPELINE_EXECUTE_H_
#define RISCV_PIPELINE_EXECUTE_H_

#include <stdbool.h>

#include "riscv/pipeline/decoded_values.h"
#include "riscv/pipeline/pipeline_stage.h"

typedef bool ExecuteShouldStallCb(void* arg);
typedef struct ExecuteShouldStall {
    ExecuteShouldStallCb* cb;
    void* arg;
} ExecuteShouldStall;

typedef DecodedValues ExecuteGetDecodedValuesInCb(void* arg);
typedef struct ExecuteGetDecodedValuesIn {
    ExecuteGetDecodedValuesInCb* cb;
    void* arg;
} ExecuteGetDecodedValuesIn;

typedef struct ExecuteParams {
    ExecuteShouldStall should_stall;
    ExecuteGetDecodedValuesIn get_decoded_values_in;
} ExecuteParams;

typedef struct Execute {
    PipelineStage super;

    ExecuteShouldStall should_stall;
    ExecuteGetDecodedValuesIn get_decoded_values_in;
} Execute;

void execute_init(Execute* execute, ExecuteParams params);
void execute_free(Execute* execute);

#endif  // RISCV_PIPELINE_EXECUTE_H_
