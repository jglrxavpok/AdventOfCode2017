//
// Created by jglrxavpok on 02/12/2017.
//

#ifndef ADVENTOFCODE2017_INTLIST_H
#define ADVENTOFCODE2017_INTLIST_H

#include <malloc.h>
#include <stdbool.h>

/**
 * Very simple integer linked list
 */
struct intlinkedlist {
    int value;
    bool hasValue;
    struct intlinkedlist *previous;
    struct intlinkedlist *next;
    struct intlinkedlist *last;
};
typedef struct intlinkedlist intlinkedlist_t;

intlinkedlist_t *mallocintlist(void);
void addintlist(intlinkedlist_t *list, int value);
void freeintlist(intlinkedlist_t *list);

#endif //ADVENTOFCODE2017_INTLIST_H
