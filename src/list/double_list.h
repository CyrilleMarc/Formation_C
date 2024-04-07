#pragma once 

typedef struct Element {
	int number;
	struct Element* back;
	struct Element* next;
} Element;

typedef struct Liste {
	Element *first;
} Liste;



Liste* double_list_init();
void double_list_insert_element(Liste* list, int number);
void double_list_display(Liste* list);
void double_list_delete_all(Liste* list);
void double_list_delete_first(Liste* list);
void double_list_delete_by_number(Liste* list, int number);

