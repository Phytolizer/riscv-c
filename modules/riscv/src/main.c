#include <inttypes.h>
#include <println/println.h>
#include <stdio.h>

#include "riscv/rvi32_system.h"

int main() {
    Rvi32System rv;
    rvi32_system_init(&rv);
    uint32_t test_rom[] = {0xDEADBEEF, 0xC0DECAFE};
    rom_device_load(&rv.rom, (UInt32Buf)BUF_ARRAY(test_rom));
    mmio_device_write(&rv.bus.super, 0x20400000, 0x01020304);
    printfln("%08" PRIx32, mmio_device_read(&rv.bus.super, 0x10000000));
    printfln("%08" PRIx32, mmio_device_read(&rv.bus.super, 0x10000004));
    printfln("%08" PRIx32, mmio_device_read(&rv.bus.super, 0x10000008));
    printfln("%08" PRIx32, mmio_device_read(&rv.bus.super, 0x20000000));
    rvi32_system_free(rv);
}
