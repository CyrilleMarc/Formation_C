#include <stdio.h>
#include <stdlib.h>

#include "single_list.h" 
#include "common/common.h"

Liste* single_list_init() {
    Liste* list = malloc(sizeof(Liste));
    Element* element = malloc(sizeof(Element));

    if (NULL == list || NULL == element) {
        logger_log(LOG_DEBUG, __FUNCSIG__, "Failed memory allocation\n");
    }
    element->number = 0;
    element->next = NULL;
    list->first = element;

    return list;
}

void single_list_insert(Liste* list, int newNumber) {
    Element* new = malloc(sizeof(Element));
    if (NULL == list || NULL == new) {
        logger_log(LOG_DEBUG, __FUNCSIG__, "Failed memory allocation\n");
    }
    new->number = newNumber;
    new->next = list->first;
    list->first = new;
}


void single_list_display(Liste* list) {
    if (NULL == list) {
        logger_log(LOG_INFO, __FUNCSIG__, "List not found\n");
        return;
    }
    Element* current = list->first;
    while (NULL != current) {
        printf("%d->", current->number);
        current = current->next;
    }  
}

void single_list_delete_first(Liste* list) {
     if (NULL == list) {
        logger_log(LOG_INFO, __FUNCSIG__, "List do not found\n");
        return;
    }
    if (NULL == list->first) {
        logger_log(LOG_INFO, __FUNCSIG__, "List is empty\n");
        return;
    }
        Element* temp = list->first;
        list->first = list->first->next;
        free(temp);
   
}
