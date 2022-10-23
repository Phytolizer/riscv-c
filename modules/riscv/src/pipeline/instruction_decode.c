#include "riscv/pipeline/instruction_decode.h"

#include <string.h>

#include "riscv/support/container_of.h"

static void instruction_decode_compute(PipelineStage* stage);
static void instruction_decode_latch_next(PipelineStage* stage);

static const PipelineStageOps ops = {
    .compute = instruction_decode_compute,
    .latch_next = instruction_decode_latch_next,
};

void instruction_decode_init(InstructionDecode* decode, InstructionDecodeParams params) {
    decode->super.ops = &ops;
    decode->super.cb_arg = decode;
    memset(&decode->d, 0, sizeof(decode->d));
    decode->should_stall = params.should_stall;
    decode->get_instruction_in = params.get_instruction_in;
}
uint32_t instruction_decode_get_instruction_out(const InstructionDecode* decode) {
    return decode->d.instruction;
}

DecodedValues instruction_decode_get_decoding(const InstructionDecode* decode) {
    return decode->d;
}

static void instruction_decode_compute(PipelineStage* stage) {
    InstructionDecode* decode = CONTAINER_OF(stage, InstructionDecode, super);
    if (!decode->should_stall.cb(decode->should_stall.arg)) {
        decode->d.instruction_next = decode->get_instruction_in.cb(decode->get_instruction_in.arg);
        decode->d.opcode_next = decode->d.instruction_next & 0x7F;
        decode->d.rd_next = (decode->d.instruction_next >> 7) & 0x1F;
        decode->d.funct3_next = (decode->d.instruction_next >> 12) & 0x07;
        decode->d.rs1_next = (decode->d.instruction_next >> 15) & 0x1F;
        decode->d.rs2_next = (decode->d.instruction_next >> 20) & 0x1F;
        decode->d.imm11_0_next = (decode->d.instruction_next >> 20) & 0x1F;
        decode->d.funct7_next = (decode->d.instruction_next >> 25) & 0x7F;
        decode->d.shamt_next = decode->d.rs2_next;
    }
}

static void instruction_decode_latch_next(PipelineStage* stage) {
    InstructionDecode* decode = CONTAINER_OF(stage, InstructionDecode, super);
    decode->d.instruction = decode->d.instruction_next;
    decode->d.opcode = decode->d.opcode_next;
    decode->d.rd = decode->d.rd_next;
    decode->d.funct3 = decode->d.funct3_next;
    decode->d.rs1 = decode->d.rs1_next;
    decode->d.rs2 = decode->d.rs2_next;
    decode->d.imm11_0 = decode->d.imm11_0_next;
    decode->d.funct7 = decode->d.funct7_next;
    decode->d.shamt = decode->d.shamt_next;
}
