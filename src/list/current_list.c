#include <stdio.h>
#include <stdlib.h>

#include <common/common.h>
#include <list/current_list.h>

Liste *init_newList_i()
{

	Liste *newListe = malloc(sizeof(Liste));
	if (NULL == newListe)
	{
		logger_log(LOG_DEBUG, __FUNCSIG__, "Memory allocation failed");
		return NULL;
	}

	Element *newElement = malloc(sizeof(Element));
	if (NULL == newElement)
	{
		logger_log(LOG_DEBUG, __FUNCSIG__, "Memory allocation failed");
		return NULL;
	}

	newElement->number = 0;
	newElement->next = NULL;
	newListe->first = newElement;
	return newListe;

}

int insert_newList_elements_i(Liste *newListe, int newNumber)
{

	Element *newElement = malloc(sizeof(Element));
	if (newElement == NULL)
	{
		logger_log(LOG_DEBUG, __FUNCSIG__, "Memory allocation failed");
		return 1;
	}
	newElement->number = newNumber;
	newElement->next = newListe->first;
	newListe->first = newElement;

	return 0;
}
