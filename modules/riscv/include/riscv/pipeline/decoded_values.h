#ifndef RISCV_PIPELINE_DECODED_VALUES_H_
#define RISCV_PIPELINE_DECODED_VALUES_H_

#include <stdint.h>

typedef struct DecodedValues {
    uint32_t instruction;
    uint32_t instruction_next;
    uint32_t opcode;
    uint32_t opcode_next;
    uint32_t rd;
    uint32_t rd_next;
    uint32_t funct3;
    uint32_t funct3_next;
    uint32_t rs1;
    uint32_t rs1_next;
    uint32_t rs2;
    uint32_t rs2_next;
    uint32_t imm11_0;
    uint32_t imm11_0_next;
    uint32_t funct7;
    uint32_t funct7_next;
    uint32_t shamt;
    uint32_t shamt_next;
} DecodedValues;

#endif  // RISCV_PIPELINE_DECODED_VALUES_H_
