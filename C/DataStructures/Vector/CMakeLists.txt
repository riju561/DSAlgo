cmake_minimum_required(VERSION 3.20)
project(vector C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_COMPILER clang)
set(CMAKE_C_FLAGS -Weverything)

add_executable(vector main.c vector.c vector.h)
