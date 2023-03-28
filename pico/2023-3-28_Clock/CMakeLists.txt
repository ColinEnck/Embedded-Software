cmake_minimum_required(VERSION 3.13)

include (pico_sdk_import.cmake)

project(clock C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(clock
	clock.c
)

pico_add_extra_outputs(clock)

target_link_libraries(clock pico_stdlib)
