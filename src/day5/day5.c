//
// Created by jglrxavpok on 05/12/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "day5.h"
#include "../ioutils.h"
#include "../intlist.h"

void runday5(int part) {
    printf("Your input?\n");
    int result;
    switch(part) {
        case 1:
            result = solveday5pt1();
            break;
        case 2:
            result = solveday5pt2();
            break;
        default:
            printf("Invalid part\n");
            return;
    }
    printf("Result is %d\n", result);
}

int solveday5pt2() {
    int charCount;
    char *row = readline(&charCount);
    int listLength = 0;
    intlinkedlist_t* jumpList = mallocintlist();
    while(charCount != 0) {
        long value = strtol(row, NULL, 10);
        addintlist(jumpList, (int)value);
        printf("Waiting for next line...\n");
        row = readline(&charCount); // read next line
        listLength++;
    }
    int position = 0;
    intlinkedlist_t* currentInstruction = jumpList;
    int steps = 0;
    while(position < listLength) {
        int jumpOffset = currentInstruction->value;
        if(jumpOffset >= 3) // increment or decrement jump offset based on value
            currentInstruction->value = jumpOffset-1;
        else
            currentInstruction->value = jumpOffset+1;
        position += jumpOffset;
        int direction = 1;
        if(jumpOffset < 0) {
            direction = -1;
        }
        int i;
        for(i = 0;i<abs(jumpOffset);i++) {
            if(direction == 1) {
                currentInstruction = currentInstruction->next;
            } else {
                currentInstruction = currentInstruction->previous;
            }
        }
        steps++;
    }
    freeintlist(jumpList);
    return steps;
}

int solveday5pt1() {
    int charCount;
    char *row = readline(&charCount);
    int listLength = 0;
    intlinkedlist_t* jumpList = mallocintlist();
    while(charCount != 0) {
        long value = strtol(row, NULL, 10);
        addintlist(jumpList, (int)value);
        printf("Waiting for next line...\n");
        row = readline(&charCount); // read next line
        listLength++;
    }
    int position = 0;
    intlinkedlist_t* currentInstruction = jumpList;
    int steps = 0;
    while(position < listLength) {
        int jumpOffset = currentInstruction->value;
        currentInstruction->value = jumpOffset+1; // increment jump offset
        position += jumpOffset;
        int direction = 1;
        if(jumpOffset < 0) {
            direction = -1;
        }
        int i;
        for(i = 0;i<abs(jumpOffset);i++) {
            if(direction == 1) {
                currentInstruction = currentInstruction->next;
            } else {
                currentInstruction = currentInstruction->previous;
            }
        }
        steps++;
    }
    freeintlist(jumpList);
    return steps;
}