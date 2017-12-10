//
// Created by jglrxavpok on 02/12/2017.
//

#ifndef ADVENTOFCODE2017_STRINGLIST_H
#define ADVENTOFCODE2017_STRINGLIST_H

#include <malloc.h>
#include <stdbool.h>

/**
 * Very simple integer linked list
 */
struct stringlinkedlist {
    char* value;
    bool hasValue;
    struct stringlinkedlist *next;
    struct stringlinkedlist *last;
    int index;
    int size;
};
typedef struct stringlinkedlist stringlinkedlist_t;

stringlinkedlist_t *mallocstringlist(void);
void addstringlist(stringlinkedlist_t *list, char *value, int size);
void freestringlist(stringlinkedlist_t *list);

#endif //ADVENTOFCODE2017_INTLIST_H
