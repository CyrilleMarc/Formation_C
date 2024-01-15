#pragma once

typedef struct Element {
    int number;
    struct Element* next;
} Element;

typedef struct Liste {
    Element* first;
} Liste;

Liste* single_list_init();
void single_list_insert(Liste* list, int newNumber);
void single_list_display(Liste* list);
void single_list_delete_first(Liste* list);
