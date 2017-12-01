cmake_minimum_required(VERSION 3.9)
project(AdventOfCode2017 C)

set(CMAKE_C_STANDARD 99)

set(SOURCE
        src/main.c
        src/day1/day1.c src/day1/day1.h src/ioutils.c src/ioutils.h)
add_executable(AdventOfCode2017 ${SOURCE})