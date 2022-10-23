#include "riscv/register32.h"

void register32_set_value(Register32* reg, int32_t value) {
    if (value < 0) {
        reg->value = (~((uint32_t)-value) + 1);
    } else {
        reg->value = (uint32_t)value;
    }
}
