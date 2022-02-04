cmake_minimum_required(VERSION 3.20)
project(4e C)

set(CMAKE_C_STANDARD 11)

add_executable(4e main.c libs/algorithms/array/array.c libs/algorithms/array/array.h libs/algorithms/algorithm.c libs/algorithms/algorithm.h libs/data_structures/bitset/bitset.c)

add_subdirectory(libs)
target_link_libraries(4e algorithms)
target_link_libraries(4e data_structures)