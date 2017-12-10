//
// Created by jglrxavpok on 02/12/2017.
//

#include "genericlist.h"
#include <stdlib.h>

genericlinkedlist_t *malloclinkedlist() {
    genericlinkedlist_t* list = malloc(sizeof(genericlinkedlist_t));
    list->value = NULL;
    list->size = 0;
    list->next = NULL;
    list->previous = NULL;
    list->hasValue = false;
    return list;
}

void addlinkedlist(genericlinkedlist_t *list, void* value, int valueSize) {
    if( ! list->hasValue) { // the list is empty, add a value to its head
        list->value = value;
        list->size = valueSize;
        list->hasValue = true;
        list->last = list;
        list->index = 0;
    } else {
        genericlinkedlist_t* next = malloclinkedlist();
        next->index = list->last->index+1;
        list->last->next = next;
        next->previous = list->last;
        list->last = next;
        next->value = value;
        next->size = valueSize;
        next->hasValue = true;
    }
}

/**
 * Also frees the value inside the list!
 * @param list
 */
void freelinkedlist(genericlinkedlist_t *list) {
    if(list->next != NULL)
        freelinkedlist(list->next);
    if(list->hasValue)
        free(list->value);
    free(list);
}