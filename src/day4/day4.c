//
// Created by jglrxavpok on 04/12/2017.
//

#include <stdio.h>
#include <mem.h>
#include <stdlib.h>
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
            addstringlist(words, word, bufferOffset-1);
            bufferOffset = 0;
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
        addstringlist(words, word, bufferOffset-1);
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

int isvalidpassnoagram(char* passphrase, int size) {
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
            addstringlist(words, word, bufferOffset-1);
            bufferOffset = 0;
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
        addstringlist(words, word, bufferOffset-1);
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
            int size1 = currentPosition1->size;
            int size2 = currentPosition2->size;

            currentPosition2 = currentPosition2->next;
            if (index1 != index2 && (strcmp(firstval, secondval) == 0 || anagrams(firstval, secondval, size1, size2))) {
                valid = 0;
                printf("no: %s %s\n", firstval, secondval);
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

bool anagrams(char *a, char *b, int asize, int bsize) {
    if(asize != bsize)
        return false;
    char* asorted = malloc(sizeof(char)*asize);
    char* bsorted = malloc(sizeof(char)*asize);
    int i;
    for (i = 0; i < asize; ++i) {
        asorted[i] = a[i];
    }
    for (i = 0; i < bsize; ++i) {
        bsorted[i] = b[i];
    }
    qsort(asorted, (size_t) asize, sizeof(char), comparechar);
    qsort(bsorted, (size_t) bsize, sizeof(char), comparechar);
    bool result = strcmp(asorted, bsorted) == 0;
    free(asorted);
    free(bsorted);
    return result;
}

static int comparechar (void const *a, void const *b)
{
    char const *pa = a;
    char const *pb = b;

    return *pa - *pb;
}

int solveday4pt2() {
    int charCount;
    char *row = readline(&charCount);
    int validCount = 0;
    while(charCount != 0) {
        validCount += isvalidpassnoagram(row, charCount);
        printf("Waiting for next line...\n");
        row = readline(&charCount); // read next line
    }

    return validCount;
}
