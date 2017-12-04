//
// Created by jglrxavpok on 02/12/2017.
//

#include "stringlist.h"

stringlinkedlist_t *mallocstringlist() {
    stringlinkedlist_t* list = malloc(sizeof(stringlinkedlist_t));
    list->value = "";
    list->next = NULL;
    list->hasValue = false;
    return list;
}

void addstringlist(stringlinkedlist_t *list, char* value) {
    if( ! list->hasValue) { // the list is empty, add a value to its head
        list->value = value;
        list->hasValue = true;
        list->last = list;
        list->index = 0;
    } else {
        stringlinkedlist_t* next = mallocstringlist();
        next->index = list->last->index+1;
        list->last->next = next;
        list->last = next;
        next->value = value;
        next->hasValue = true;
    }
}

/**
 * Also frees the value inside the list!
 * @param list
 */
void freestringlist(stringlinkedlist_t *list) {
    if(list->next != NULL)
        freestringlist(list->next);
    if(list->hasValue)
        free(list->value);
    free(list);
}