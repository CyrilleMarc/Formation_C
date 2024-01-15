#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <common/common.h>
#include <algorithmie/algorithmie.h>

int main(int argc, char* argv[])
{
	logger_set_current_level(LOG_DEBUG);
	logger_log(LOG_DEBUG, __FUNCSIG__, argv[0]);

	int i = 0;
	int* array_to_test = NULL;
	int array_element_count = 5000;
	int max_value = 16384;
	int number_sorted = 0;

	function_array_to_test(&array_to_test, array_element_count, max_value);
	number_sorted = array_to_check_sorted_number(array_to_test, array_element_count);
	printf("*****\n");
	printf("****************RESULT*************\n");
	printf("%d", number_sorted);
	printf("\n");

	clock_t start1, end1, start2, end2;
	double cpu_time_used1, cpu_time_used2;

	start1 = clock();
	function_array_to_sort(array_to_test, array_element_count);
	printf("********************BUBBLE SORT******************\n");
	for(i = 0; i < array_element_count; ++i) {
			printf("%d-> ", array_to_test[i]);
}
	for (i = 0; i < array_element_count; ++i){
		if (array_to_test[i] <= array_to_test[i + 1]);
	}
	logger_log(LOG_INFO, __FUNCSIG__, "Array successfully sorted\n");
	printf("\n");
	end1 = clock();
	cpu_time_used1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
	
	start2 = clock();
	function_array_insertion_sort_i(array_to_test, array_element_count);
	printf("********************Array sorted******************\n");
	for(i = 0; i < array_element_count; ++i) {
			printf("%d-> ", array_to_test[i]);
}
	for (i = 0; i < array_element_count; ++i) {
		if (array_to_test[i] <= array_to_test[i + 1]);
	}
	logger_log(LOG_INFO, __FUNCSIG__, "Array successfully sorted");
	
	printf("\n");
	end2 = clock();
	cpu_time_used2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
	printf("\n");
	printf("Temps d'execution de l'algorithme de bubble_sort : %f secondes\n", cpu_time_used1);
	printf("Temps d'execution de l'algorithme de insertion_sort : %f secondes\n", cpu_time_used2);
}
