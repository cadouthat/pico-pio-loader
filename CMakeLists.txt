cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(pico_pio_loader C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_library(pico_pio_loader
  src/pico_pio_loader.cpp)

target_include_directories(pico_pio_loader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(pico_pio_loader PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src )

target_link_libraries(pico_pio_loader
  pico_stdlib
  hardware_pio
)
