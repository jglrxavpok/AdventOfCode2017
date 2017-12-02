//
// Created by jglrxavpok on 02/12/2017.
//

#include <stdio.h>
#include <limits.h>
#include "day2.h"
#include "../ioutils.h"
#include "../intlist.h"

int solveday2pt1() {
    int charCount;
    char *row = readline(&charCount);
    int checksum = 0;
    while(charCount != 0) {
        checksum += findchecksum(row);
        row = readline(&charCount); // read next line
    }
    return checksum;
}

int findchecksum(char *row) {
    unsigned int currentNumber = 0;
    unsigned int max = 0;
    unsigned int min = INT_MAX;
    while(*row != '\n') {
        char c = *row;
        if(c >= '0' && c <= '9') {
            currentNumber *= 10;
            currentNumber += c - '0';
        } else {
            if(currentNumber > max)
                max = currentNumber;
            if(currentNumber < min)
                min = currentNumber;
            currentNumber = 0;
        }
        row++;
    }
    if(currentNumber > max)
        max = currentNumber;
    if(currentNumber < min)
        min = currentNumber;
    return max-min;
}

int findchecksum2(char *row) {
    intlinkedlist_t *nblist = mallocintlist();
    unsigned int currentNumber = 0;
    while(*row != '\n' && *row != EOF) {
        char c = *row;
        if(c >= '0' && c <= '9') {
            currentNumber *= 10;
            currentNumber += c - '0';
        } else {
            addintlist(nblist, currentNumber);
            currentNumber = 0;
        }
        row++;
    }
    addintlist(nblist, currentNumber);

    intlinkedlist_t* currentPosition1 = nblist;
    intlinkedlist_t* currentPosition2 = nblist;
    int result = -1;
    while(currentPosition1 != NULL && currentPosition1->hasValue) { // iterate all pairs possible (O(n^2), probably not the best way to do it)
        while(currentPosition2 != NULL && currentPosition2->hasValue) {
            int firstval = currentPosition1->value;
            int secondval = currentPosition2->value;

            currentPosition2 = currentPosition2->next;

            if(firstval == secondval) // do not check a number against itself
                continue;
            if(firstval % secondval == 0) {
                result = firstval / secondval;
            }
        }
        currentPosition2 = nblist;
        currentPosition1 = currentPosition1->next;
    }
    freeintlist(nblist);
    return result;
}

int solveday2pt2() {
    int charCount;
    char *row = readline(&charCount);
    int checksum = 0;
    while(charCount != 0) {
        int rowChecksum = findchecksum2(row);
        checksum += rowChecksum;
        printf("%s : %d!!", row, rowChecksum);
        row = readline(&charCount); // read next line
    }
    return checksum;
}

void runday2() {
    printf("Which part ?\n");
    int part;
    scanf("%d", &part);
    getchar();
    printf("Your input?\n");
    int result;
    if(part == 1) {
        result = solveday2pt1();
    } else if(part == 2) {
        result = solveday2pt2();
    } else {
        printf("Invalid part!\n");
        return;
    }
    printf("The answer is %d\n", result);
}