#pragma once

typedef struct Element {
	int number;
	struct Element* next;
	struct Element* back;
}Element; 

typedef struct Liste {
	Element* first;
}Liste;

Liste* init_newDoubleList_i();
int insert_element_in_doubleListe_i(Liste* liste, int newNumber);
void list_sort(Liste* liste);
int list_is_sorted(Liste* list);
void freeList(Liste* liste);
int init_file_to_store(const char *fileName, double *content, int liste_element_count);
int create_random_value_file(const char* fileName);
int retrieve_data_from_file(const char* fileName, const char* fileName2);


