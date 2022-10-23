#ifndef RISCV_STATE_H_
#define RISCV_STATE_H_

typedef enum State {
#define X(x) STATE_##x,
#include "riscv/state.inc"
#undef X
} State;

#endif  // RISCV_STATE_H_
