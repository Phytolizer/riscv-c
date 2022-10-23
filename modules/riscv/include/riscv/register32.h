#ifndef RISCV_REGISTER32_H_
#define RISCV_REGISTER32_H_

#include <stdint.h>

typedef struct Register32 {
    uint32_t value;
} Register32;

void register32_set_value(Register32* reg, int32_t value);

#endif  // RISCV_REGISTER32_H_
