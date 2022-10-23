#ifndef RISCV_SYSTEM_INTERFACE_MEMORY_MAP_H_
#define RISCV_SYSTEM_INTERFACE_MEMORY_MAP_H_

typedef enum MemoryMap {
#define X(x, v) MEMORY_MAP_##x = v,
#include "riscv/system_interface/memory_map.inc"
#undef X
} MemoryMap;

#endif  // RISCV_SYSTEM_INTERFACE_MEMORY_MAP_H_
