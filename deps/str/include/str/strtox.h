#pragma once

#include <stdint.h>

#include "str/str.h"

#define STRTOX_RESULT(T) \
    struct { \
        T value; \
        const char* endptr; \
        int err; \
    }

typedef STRTOX_RESULT(uint64_t) Str2U64Result;

Str2U64Result str_to_u64(str in, int base);

typedef STRTOX_RESULT(int64_t) Str2I64Result;

// NOTE: Does not handle negative numbers!
Str2I64Result str_to_i64(str s, int base);
