#include <stdio.h>
#include <stdlib.h>

#include "list/double_list.h" 
#include "common/common.h"

Liste* double_list_init() {
	Liste* list = malloc(sizeof(Liste));

	if (NULL == list) {
		logger_log(LOG_DEBUG, __FUNCSIG__, "Failed memory allocation\n");
	}
	list->first = NULL;
	return list;

}	

void double_list_insert_element(Liste* list, int number) {
	Element *new_element = malloc(sizeof(Element));
	if (NULL == new_element) {
		logger_log(LOG_DEBUG, __FUNCSIG__, "Failed memory allocation\n");
	}

	new_element->number = number;
	new_element->next = NULL;
	new_element->back = NULL;

	if (NULL == list->first) {
		list->first = new_element;
	}
	else {
		Element* current = list->first;
		while (NULL != current->next) {
			current = current->next;
		}
		current->next = new_element;
		new_element->back = current;
	}

}

void double_list_display(Liste* list) {
	logger_log(LOG_INFO, __FUNCSIG__, "\nLa liste:\n");
	Element* current = list->first;
	while (NULL != current) {
		printf("%d->", current->number);
		current = current->next;
	}
}

void double_list_delete_first(Liste *list) {
	if(NULL != list->first){
		Element* firstElement = list->first;
		list->first = firstElement->next;
		if (NULL != list->first) {
			(list->first->back = NULL);
		}
		free(firstElement);
	}
	
}


void double_list_delete_by_number(Liste* list, int number) {
	Element* current = list->first;
	while (current != NULL) {
		if (current->number == number) {
			if (current->back != NULL) {
				current->back->next = current->next;
			}
			if (current->next != NULL) {
				current->next->back = current->back;
			}
			if (list->first == current) {
				list->first = current->next;
			}
			free(current);
			break;
		}
		current = current->next;
	}
}

void double_list_delete_all(Liste* list) {
	Element* current = list->first;
	while (NULL != current) {
		Element* temp = current;
		current = current->next;
		free(temp);
	}
	list->first = NULL;
}