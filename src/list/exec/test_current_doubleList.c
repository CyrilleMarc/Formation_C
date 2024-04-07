#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <common/common.h>
#include <list/current_doubleList.h>



int main(int argc, int* argv)
{
	logger_set_current_level(LOG_DEBUG);
	logger_log(LOG_DEBUG, __FUNCSIG__, "");

	int i = 2;
	const char *fileName = "C:/Users/cyril/Desktop/dataFiles/complexity.txt";
	const char* fileName2 = "C:/Users/cyril/Desktop/dataFiles/datasorted.txt";
	const char* fileName3 = "C:/Users/cyril/Desktop/dataFiles/randomData.txt";
	int liste_element_count = 0;

	while (i < 12)
	{
		int liste_element_count = pow(2, i);
		int maxValue = 8192;
		printf("**********************ITERATION %d*****************\n", i);

		Liste* liste = init_newDoubleList_i();
		if (NULL == liste) {
			logger_log(LOG_DEBUG, __FUNCSIG__, "List not found");
			return 1;
		}
		srand(time(NULL));
		for (int i = 0; i < liste_element_count; ++i)
		{
			int randomValue = rand() % (maxValue + 1);
			insert_element_in_doubleListe_i(liste, randomValue);
		}

		Element* doubleCurrent = liste->first;
		printf("***********no sorted list****************\n");
		while (doubleCurrent != NULL) {
			printf("%d ", doubleCurrent->number);
			doubleCurrent = doubleCurrent->next;
		}
		printf("\n");

		clock_t start1, end1 = 0;
		double cpu_time_used1 = 0;

		list_sort(liste);
		printf("**********sorted list***********\n");
		start1 = clock();
		Element* currentSort = liste->first;
		for (int i = 0; i < liste_element_count; ++i)
		{
			printf("%d ", currentSort->number);
			currentSort = currentSort->next;
		}
		printf("\n");
		end1 = clock();
		cpu_time_used1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
		printf("L'algorithme de tri a mis : %f secondes\n", cpu_time_used1);
		printf("Nombre d'entree n : %d\n", liste_element_count);
		++i;

		if (list_is_sorted(liste))
		{
			printf("List sorted successfully");
			printf("\n\n");
		}
		else
		{
			printf("List sorted Failure");
			printf("\n\n");
		}

		init_file_to_store(fileName, &cpu_time_used1, liste_element_count);
		double *content = 0;
		retrieve_data_from_file(fileName, fileName2);
		freeList(liste);
	}
		create_random_value_file(fileName3);
	return 0;
}

