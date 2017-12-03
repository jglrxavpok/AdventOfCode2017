//
// Created by jglrxavpok on 01/12/2017.
//

#include <stdio.h>
#include "day1.h"
#include "../ioutils.h"

int solveday1pt1(char *input) {
    char previous = '\0';
    char first = '\0';
    int sum = 0;
    if(*input != 0)
        first = *input;
    while(*input != 0) { // while not at end of input
        char current = *input;
        input++;
        if(current == '\n')
            continue;
        if(current == previous) {
            int digit = current - '0'; // convert to digit
            sum += digit;
        }
        previous = current;
    }
    if(previous == first) {// 'previous' holds the last character read at this state
        sum += first - '0';
    }
    return sum;
}

int solveday1pt2(char *input, int inputSize) {
    int sum = 0;
    int i;
    int halfsize = inputSize/2;
    for(i = 0; i < inputSize; i++) {
        char current = *(input + i);
        if(current == '\n')
            continue;
        int halfwayidx = (i + halfsize) % inputSize;
        char halfway = *(input + halfwayidx);
        if(current == halfway) {
            int digit = current - '0'; // convert to digit
            sum += digit;
        }
    }
    return sum;
}

void runday1(int part) {
    printf("Your input?\n");
    int inputSize;
    int result;
    if(part == 1) {
        result = solveday1pt1(readline(&inputSize));
    } else if(part == 2) {
        char* line = readline(&inputSize);
        result = solveday1pt2(line, inputSize);
    } else {
        printf("Invalid part!\n");
        return;
    }
    printf("The answer is %d\n", result);
}