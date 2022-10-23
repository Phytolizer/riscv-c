cmake_minimum_required(VERSION 3.23)

project(
  riscv
  LANGUAGES C
  DESCRIPTION "RISC-V emulator"
)

if(RISCV_SANITIZE)
  string(APPEND CMAKE_C_FLAGS
         " -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer"
  )
  string(APPEND CMAKE_EXE_LINKER_FLAGS
         " -fsanitize=address -fsanitize=undefined"
  )
endif()

set(CMAKE_C_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_subdirectory(deps/hedley)

add_subdirectory(deps/str)
add_subdirectory(deps/sum)

add_subdirectory(deps/buf)
add_subdirectory(deps/file)
add_subdirectory(deps/println)

configure_file(cmake/config.h.cmake-in include/config.h)

add_library(config_h INTERFACE)
target_include_directories(
  config_h INTERFACE "${CMAKE_CURRENT_BINARY_DIR}/include"
)
add_library(riscv::config_h ALIAS config_h)

add_subdirectory(modules/riscv)
