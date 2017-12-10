//
// Created by jglrxavpok on 02/12/2017.
//

#ifndef ADVENTOFCODE2017_GENERICLIST_H
#define ADVENTOFCODE2017_GENERICLIST_H

#include <malloc.h>
#include <stdbool.h>

/**
 * Very simple integer linked list
 */
struct genericlinkedlist {
    void* value;
    bool hasValue;
    struct genericlinkedlist *next;
    struct genericlinkedlist *last;
    struct genericlinkedlist *previous;
    int index;
    int size;
};
typedef struct genericlinkedlist genericlinkedlist_t;

genericlinkedlist_t *malloclinkedlist(void);
void addlinkedlist(genericlinkedlist_t *list, void *value, int size);
void freelinkedlist(genericlinkedlist_t *list);

#endif //ADVENTOFCODE2017_INTLIST_H
