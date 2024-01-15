#pragma once

typedef struct Element
{
	int number;
	struct Element *next;
} Element;

typedef struct Liste
{
	Element *first;
} Liste;


Liste *init_newList_i();
int insert_newList_elements_i(Liste *newListe, int liste_element_count);

