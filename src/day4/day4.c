//
// Created by jglrxavpok on 04/12/2017.
//

#include <stdio.h>
#include <mem.h>
#include "day4.h"
#include "../ioutils.h"
#include "../stringlist.h"

void runday4(int part) {
    printf("Your input?\n");
    int result;
    switch(part) {
        case 1:
            result = solveday4pt1();
            break;
        case 2:
            result = solveday4pt2();
            break;
        default:
            printf("Invalid part\n");
            return;
    }
    printf("Result is %d\n", result);
}

int solveday4pt1() {
    int charCount;
    char *row = readline(&charCount);
    int validCount = 0;
    while(charCount != 0) {
        validCount += isvalidpass(row, charCount);
        printf("Waiting for next line...\n");
        row = readline(&charCount); // read next line
    }

    return validCount;
}

int isvalidpass(char* passphrase, int size) {
    stringlinkedlist_t* words = mallocstringlist();
    char buffer[size];
    int bufferOffset = 0;
    int i;
    for(i = 0;i < size;i++) {
        if(passphrase[i] == ' ' || passphrase[i] == '\n') {
            if(bufferOffset == 0)
                continue;
            // copy to list
            buffer[bufferOffset++] = '\0';
            char *word = malloc(sizeof(char)*bufferOffset);
            int j;
            for(j = 0;j<bufferOffset;j++) {
                word[j] = buffer[j];
            }
            bufferOffset = 0;
            addstringlist(words, word);
        } else {
            buffer[bufferOffset++] = passphrase[i];
        }
    }
    if(bufferOffset != 0) { // add last word if needed
        buffer[bufferOffset++] = '\0';
        char *word = malloc(sizeof(char)*bufferOffset);
        int j;
        for(j = 0;j<bufferOffset;j++) {
            word[j] = buffer[j];
        }
        addstringlist(words, word);
    }
    int valid = 1;
    stringlinkedlist_t* currentPosition1 = words;
    stringlinkedlist_t* currentPosition2 = words;
    while(currentPosition1 != NULL && currentPosition1->hasValue) { // iterate all pairs possible (O(n^2), probably not the best way to do it)
        while (currentPosition2 != NULL && currentPosition2->hasValue) {
            char* firstval = currentPosition1->value;
            char* secondval = currentPosition2->value;
            int index1 = currentPosition1->index;
            int index2 = currentPosition2->index;

            currentPosition2 = currentPosition2->next;
            if (index1 != index2 && strcmp(firstval, secondval) == 0) {
                valid = 0;
                break;
            }
        }
        currentPosition2 = words;
        currentPosition1 = currentPosition1->next;
    }
    freestringlist(words);
    free(buffer);
    return valid;
}

int solveday4pt2() {
    return -1;
}
