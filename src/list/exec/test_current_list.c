#include <stdio.h>
#include <stdlib.h>

#include <common/common.h>
#include <list/current_list.h>


int main(int argc, int* argv)
{
	logger_set_current_level(LOG_DEBUG);
	logger_log(LOG_DEBUG, __FUNCSIG__, "");

	int liste_element_count = 20;

	Liste* newListe = init_newList_i();
	if (NULL == newListe) {
		logger_log(LOG_DEBUG, __FUNCSIG__, "Liste not found");
		return 1;
	}
	for (int i = 0; i < liste_element_count; ++i) {
		insert_newList_elements_i(newListe, i);
	}
	Element* current = newListe->first;
	while (current != NULL) {
		printf("%d ", current->number);
		current = current->next;
	}
	return 0;
}