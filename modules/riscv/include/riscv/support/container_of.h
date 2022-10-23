#ifndef RISCV_SUPPORT_CONTAINER_OF_H_
#define RISCV_SUPPORT_CONTAINER_OF_H_

#include <stddef.h>

#define CONTAINER_OF(ptr, type, member) ((type*)((char*)(ptr)-offsetof(type, member)))

#endif  // RISCV_SUPPORT_CONTAINER_OF_H_
