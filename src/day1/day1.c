//
// Created by jglrxavpok on 01/12/2017.
//

#include "day1.h"

int solveday1(char* input) {
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