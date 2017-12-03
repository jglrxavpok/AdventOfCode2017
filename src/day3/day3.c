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


void setgrid(grid_t *grid, int x, int y, int value) {
    if(x < 0) {
        x = 2*abs(x)+1;
    } else {
        x = 2*x;
    }
    if(y < 0) {
        y = 2*abs(y)+1;
    } else {
        y = 2*y;
    }
    (*grid)[x][y] = value;
}

int getgrid(grid_t *grid, int x, int y) {
    // positive numbers get assigned to even numbers
    // negative numbers get assigned to odd numbers
    if(x < 0) {
        x = 2*abs(x)+1;
    } else {
        x = 2*x;
    }
    if(y < 0) {
        y = 2*abs(y)+1;
    } else {
        y = 2*y;
    }
    return (*grid)[x][y];
}

int solveday3pt2(int input) {
    int grid[GRID_SIZE][GRID_SIZE]; // I'm sorry
    int i;
    for(i=0;i<GRID_SIZE;i++) {
        int j;
        for(j=0;j<GRID_SIZE;j++) {
            grid[i][j] = 0; // initialize grid to 0s
        }
    }
    grid[0][0] = 1;
    int curx = 0;
    int cury = 0;
    unsigned int offset = 1;
    int direction = 1;
    int value = 1;
    bool xaxis = true;
    bool found = false;
    while(value <= input) { // spiral outwards until going over the requested square
        int axis;
        for(axis = 0; axis < 2; axis++) {
            for(i = 0; i<offset;i++) {
                if(xaxis) {
                    curx += direction;
                } else {
                    cury += direction;
                }
                int sum = 0;
                sum += getgrid(&grid, curx-1, cury);
                sum += getgrid(&grid, curx+1, cury);
                sum += getgrid(&grid, curx-1, cury-1);
                sum += getgrid(&grid, curx, cury-1);
                sum += getgrid(&grid, curx+1, cury-1);
                sum += getgrid(&grid, curx-1, cury+1);
                sum += getgrid(&grid, curx, cury+1);
                sum += getgrid(&grid, curx+1, cury+1);
                setgrid(&grid, curx, cury, sum);
                value = sum;
                if(sum > input) {
                    found = true; // not going to use goto
                    break;
                }
            }
            xaxis = !xaxis;
            if(found)
                break;
        }
        offset++;
        direction *= -1;
        if(found)
            break;
    }

    int j;
    for(j = 0;j<GRID_SIZE;j++) {
        free(grid[j]);
    }
    free(grid);
    return value;
}

void runday3(int part) {
    printf("Your input?\n");
    int result;
    switch(part) {
        case 1:
            result = solveday3pt1(readnumber());
            break;
        case 2:
            result = solveday3pt2(readnumber());
            break;
        default:
            printf("Invalid part\n");
            return;
    }
    printf("Result is %d\n", result);
}