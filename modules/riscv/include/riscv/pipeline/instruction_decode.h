#ifndef RISCV_PIPELINE_INSTRUCTION_DECODE_H_
#define RISCV_PIPELINE_INSTRUCTION_DECODE_H_

#include <stdint.h>

#include "riscv/pipeline/decoded_values.h"
#include "riscv/pipeline/pipeline_stage.h"

typedef bool InstructionDecodeShouldStallCallback(void* arg);
typedef struct InstructionDecodeShouldStall {
    InstructionDecodeShouldStallCallback* cb;
    void* arg;
} InstructionDecodeShouldStall;

typedef uint32_t InstructionDecodeGetInstructionInCallback(void* arg);
typedef struct InstructionDecodeGetInstructionIn {
    InstructionDecodeGetInstructionInCallback* cb;
    void* arg;
} InstructionDecodeGetInstructionIn;

typedef struct InstructionDecode {
    PipelineStage super;

    DecodedValues d;
    InstructionDecodeShouldStall should_stall;
    InstructionDecodeGetInstructionIn get_instruction_in;
} InstructionDecode;

typedef struct InstructionDecodeParams {
    InstructionDecodeShouldStall should_stall;
    InstructionDecodeGetInstructionIn get_instruction_in;
} InstructionDecodeParams;

void instruction_decode_init(InstructionDecode* decode, InstructionDecodeParams params);
uint32_t instruction_decode_get_instruction_out(const InstructionDecode* decode);
DecodedValues instruction_decode_get_decoding(const InstructionDecode* decode);

#endif  // RISCV_PIPELINE_INSTRUCTION_DECODE_H_
