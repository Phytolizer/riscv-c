#include "riscv/rvi32_system.h"

static bool ifetch_should_stall(void* arg);
static bool idecode_should_stall(void* arg);
static uint32_t idecode_get_instruction_in(void* arg);

void rvi32_system_init(Rvi32System* system) {
    system->state = STATE_INSTRUCTION_FETCH;
    rom_device_init(&system->rom);
    ram_device_init(&system->ram);
    system_interface_init(&system->bus, &system->rom, &system->ram);
    instruction_fetch_init(
        &system->ifetch,
        (InstructionFetchParams){
            .bus = &system->bus,
            .should_stall =
                (InstructionFetchShouldStall){
                    .cb = ifetch_should_stall,
                    .arg = system,
                },
        }
    );

    instruction_decode_init(
        &system->idecode,
        (InstructionDecodeParams){
            .should_stall =
                (InstructionDecodeShouldStall){
                    .cb = idecode_should_stall,
                    .arg = system,
                },
            .get_instruction_in =
                (InstructionDecodeGetInstructionIn){
                    .cb = idecode_get_instruction_in,
                    .arg = &system->ifetch,
                },
        }
    );
}

void rvi32_system_free(const Rvi32System system) {
    rom_device_free(system.rom);
    ram_device_free(system.ram);
}

void rvi32_system_compute(Rvi32System* system) {
    // TODO: Implement.
    (void)system;
}

void rvi32_system_latch_next(Rvi32System* system) {
    // TODO: Implement.
    (void)system;
}

void rvi32_system_cycle(Rvi32System* system) {
    rvi32_system_compute(system);
    rvi32_system_latch_next(system);
}

static bool ifetch_should_stall(void* arg) {
    const Rvi32System* system = arg;
    return system->state != STATE_INSTRUCTION_FETCH;
}

static bool idecode_should_stall(void* arg) {
    const Rvi32System* system = arg;
    return system->state != STATE_DECODE;
}

static uint32_t idecode_get_instruction_in(void* arg) {
    InstructionFetch* ifetch = arg;
    return instruction_fetch_get_instruction_out(ifetch);
}
