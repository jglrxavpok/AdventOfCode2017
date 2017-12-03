//
// Created by jglrxavpok on 03/12/2017.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "day3.h"
#include "../ioutils.h"

// 'brute force' solving: go through all squares
int solveday3pt1(int input) {
    int curx = 0;
    int cury = 0;
    unsigned int offset = 1;
    int direction = 1;
    int squarenum = 1;
    bool xaxis = true;
    while(squarenum < input) { // spiral outwards until going over the requested square
        squarenum += offset;
        if(xaxis) {
            curx += offset * direction;
        } else {
            cury += offset * direction;
            offset++;
            direction *= -1;
        }

        xaxis = !xaxis;
    }
    if(squarenum > input) { // backtrack to the correct square if needed
        int error = (squarenum-input);
        xaxis = !xaxis;
        if(xaxis) {
            curx -= error*direction;
        } else {
            cury += error*direction;
        }
    }
    return abs(curx)+abs(cury); // Manhattan distance
}

int solveday3pt2(char *input) {
    return -1;
}

void runday3(int part) {
    printf("Your input?\n");
    int result;
    switch(part) {
        case 1:
            result = solveday3pt1(readnumber());
            break;
        case 2:
            result = solveday3pt2("");
            break;
        default:
            printf("Invalid part\n");
            return;
    }
    printf("Result is %d\n", result);
}