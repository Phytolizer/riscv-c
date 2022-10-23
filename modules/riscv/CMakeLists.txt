add_executable(
  riscv
  src/main.c
  src/system_interface/mmio_device.c
  src/system_interface/system_interface.c
  src/system_interface/rom_device.c
  src/system_interface/ram_device.c
  src/rvi32_system.c
  src/register32.c
  src/pipeline/pipeline_stage.c
  src/pipeline/instruction_fetch.c
)
target_link_libraries(
  riscv PRIVATE buf::buf str::str println::println file::file
)
target_include_directories(riscv PRIVATE include)

if(RISCV_WFLAGS)
  target_compile_options(
    riscv PRIVATE -Wall -Wextra -Wpedantic -Wmissing-prototypes
                  -Wno-unused-function -Wno-missing-field-initializers
  )
endif()
