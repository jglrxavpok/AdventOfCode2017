//
// Created by jglrxavpok on 06/12/2017.
//

#include <stdio.h>
#include <stdbool.h>
#include <zconf.h>
#include "day6.h"
#include "../ioutils.h"
#include "../intlist.h"
#include "../genericlist.h"

void runday6(int part) {
    printf("Your input?\n");
    int result;
    switch(part) {
        case 1:
            result = solveday6pt1();
            break;
        case 2:
            result = solveday6pt2();
            break;
        default:
            printf("Invalid part\n");
            return;
    }
    printf("Result is %d\n", result);
}

int solveday6pt1() {
    int iterations;
    int length;
    solveday6(&iterations, &length);
    return iterations;
}

void solveday6(int* iterationcount, int* cyclelength) {
    int charCount;
    char* row = readline(&charCount);
    unsigned int currentNumber = 0;
    bool inNumber = false;
    intlinkedlist_t* memoryBanks = mallocintlist();
    int bankcount = 0;
    while(*row != '\n') {
        char c = *row;
        if(c >= '0' && c <= '9') {
            currentNumber *= 10;
            currentNumber += c - '0';
            inNumber = true;
        } else {
            inNumber = false;
            addintlist(memoryBanks, currentNumber);
            currentNumber = 0;
            bankcount++;
        }
        row++;
    }
    if(inNumber) { // add last number if needed
        addintlist(memoryBanks, currentNumber);
        bankcount++;
    }

    // list of int*
    genericlinkedlist_t* configurations = malloclinkedlist();

    int iterations = 0;
    int previndex;
    do {
        saveConfiguration(memoryBanks, bankcount, configurations);
        intlinkedlist_t* max = findMax(memoryBanks);
        int remainingBlocks = max->value;
        max->value = 0;

        intlinkedlist_t* cell = max->next;

        while(remainingBlocks > 0) {
            if(cell == NULL || !cell->hasValue) {
                cell = memoryBanks; // go back to start
            }
            cell->value++;
            cell = cell->next;
            remainingBlocks--;
        }

        iterations++;
    } while(!alreadySeen(memoryBanks, bankcount, configurations, &previndex));
    freeintlist(memoryBanks);
    free(configurations);

    *iterationcount = iterations;
    *cyclelength = (iterations-previndex);
}

intlinkedlist_t* findMax(intlinkedlist_t *banks) {
    int max = INT_MIN;
    intlinkedlist_t *maxCell = banks;
    intlinkedlist_t *cell = banks;
    while(cell != NULL) {
        if(cell->value > max) {
            max = cell->value;
            maxCell = cell;
        }
        cell = cell->next;
    }

    return maxCell;
}

bool alreadySeen(intlinkedlist_t *banks, int bankcount, genericlinkedlist_t *configurations, int *index) {
    genericlinkedlist_t *currentConfig = configurations;
    bool found = false;
    while(currentConfig != NULL) {
        int* config = (int*) (currentConfig->value);

        intlinkedlist_t *currentCell = banks;
        int i;
        bool equal = true;
        for (i = 0; i < bankcount; ++i) {
            if(config[i] != currentCell->value) {
                equal = false;
                break;
            }
            currentCell = currentCell->next;
        }

        if(equal) {
            found = true;
            *index = currentConfig->index;
            break;
        }
        currentConfig = currentConfig->next;
    }
    return found;
}

void saveConfiguration(intlinkedlist_t *banks, int count, genericlinkedlist_t *destination) {
    int* config = malloc(sizeof(int)*count);
    int i;
    intlinkedlist_t *currentCell = banks;
    for (i = 0; i < count; ++i) {
        config[i] = currentCell->value;
        currentCell = currentCell->next;
    }
    addlinkedlist(destination, config, sizeof(int)*count);
}

int solveday6pt2() {
    int iterations;
    int length;
    solveday6(&iterations, &length);
    return length;
}
