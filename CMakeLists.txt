cmake_minimum_required(VERSION 3.9)
project(AdventOfCode2017 C)

set(CMAKE_C_STANDARD 99)

set(SOURCE
        src/main.c
        src/day1/day1.c src/day1/day1.h src/ioutils.c src/ioutils.h src/day2/day2.c src/day2/day2.h src/intlist.c src/intlist.h src/day3/day3.c src/day3/day3.h src/day4/day4.c src/day4/day4.h
        src/stringlist.c src/stringlist.h src/day5/day5.c src/day5/day5.h)
add_executable(AdventOfCode2017 ${SOURCE})