cmake_minimum_required(VERSION 3.20)
project(4e C)

set(CMAKE_C_STANDARD 11)

# определение точки входа. Будет запущен файл main .c.
# указывается произвольная метка, в данном случае - project
add_executable(4e main.c libs/algorithms/array/array.h
        libs/algorithms/array/array.c)