//
// Created by jglrxavpok on 06/12/2017.
//

#ifndef ADVENTOFCODE2017_DAY6_H
#define ADVENTOFCODE2017_DAY6_H

#include "../genericlist.h"
#include "../intlist.h"

void runday6(int part);
int solveday6pt1();
int solveday6pt2();

void saveConfiguration(intlinkedlist_t *banks, int count, genericlinkedlist_t *destination);
bool alreadySeen(intlinkedlist_t *banks, int bankcount, genericlinkedlist_t *configurations, int *index);
intlinkedlist_t* findMax(intlinkedlist_t *banks);

void solveday6(int* iterationcount, int* cyclelength);
#endif //ADVENTOFCODE2017_DAY6_H
