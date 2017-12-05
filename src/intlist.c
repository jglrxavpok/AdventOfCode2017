//
// Created by jglrxavpok on 02/12/2017.
//

#include <stdlib.h>
#include "intlist.h"

intlinkedlist_t *mallocintlist() {
    intlinkedlist_t* list = malloc(sizeof(intlinkedlist_t));
    list->value = 0;
    list->next = NULL;
    list->previous = NULL;
    list->hasValue = false;
    return list;
}

void addintlist(intlinkedlist_t *list, int value) {
    if( ! list->hasValue) { // the list is empty, add a value to its head
        list->value = value;
        list->hasValue = true;
        list->last = list;
    } else {
        intlinkedlist_t* next = mallocintlist();
        list->last->next = next;
        next->previous = list->last;
        list->last = next;
        next->value = value;
        next->hasValue = true;
    }
}

void freeintlist(intlinkedlist_t *list) {
    if(list->next != NULL)
        freeintlist(list->next);
    free(list);
}