#include <stdlib.h>

#include <common/common.h>
#include <list/single_list.h>

int main(int argc, char* argv[])
{
	logger_set_current_level(LOG_DEBUG);
	logger_log(LOG_DEBUG, __FUNCSIG__, argv[0]);

	Liste* newList = single_list_init();

	for (int i = 0; i <= 20; ++i) {
		single_list_insert(newList, i);
	}

	single_list_display(newList); 
	/*
	Element* current = newList->first;
	while (NULL != current) {
		printf("%d->", current->number);
		current = current->next;
	}*/

	single_list_delete_first(newList);
	printf("\n");

    single_list_display(newList);
	/*
	Element* newCurrent = newList->first;
	while (NULL != newCurrent) {
		printf("%d->", newCurrent->number);
		newCurrent = newCurrent->next;
	}*/



}
