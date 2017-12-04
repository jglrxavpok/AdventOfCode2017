//
// Created by jglrxavpok on 04/12/2017.
//

#ifndef ADVENTOFCODE2017_DAY4_H
#define ADVENTOFCODE2017_DAY4_H

#include <stdbool.h>

void runday4(int part);
int solveday4pt1();
int solveday4pt2();

int isvalidpass(char* passphrase, int size);
int isvalidpassnoagram(char* passphrase, int size);
bool anagrams(char* a, char* b, int asize, int bsize);
static int comparechar (void const *a, void const *b);
#endif //ADVENTOFCODE2017_DAY4_H
