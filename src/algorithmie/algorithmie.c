#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <common/common.h>
#include <algorithmie/algorithmie.h>


void function_array_to_test(int **array_to_malloc, int array_element_count, int max_value) {
	*array_to_malloc = malloc(array_element_count * sizeof(int));
	if (NULL == *array_to_malloc) {
		logger_log(LOG_DEBUG, __FUNCSIG__, "memory allocation failed");
	}
	else {
		logger_log(LOG_INFO, __FUNCSIG__, "memory allocated successfully");
		srand(time(NULL));
		for (int i = 0; i < array_element_count; ++i){
			(*array_to_malloc)[i] = rand() % (max_value + 1);
			printf("%d->", (*array_to_malloc)[i]);
		}
		return *array_to_malloc;
	}
	free(*array_to_malloc);
}

int array_to_check_sorted_number(int *array_to_check,int array_element_count) {
	int i = 0;
	int number_sorted = 0;

	for (i = 0; i < array_element_count - 1; ++i) {
		if (array_to_check[i] <= array_to_check[i + 1]) {
			number_sorted++;
		}
}
	return number_sorted;

}

int function_array_to_sort(int* array_to_sort, int array_element_count) {
	int temp = 0;
	int i = 0;
	int j = 0;


	for (i = 0; i < array_element_count; i++) {
		for (j = 0; j < array_element_count - 1; j++) {
			if (array_to_sort[j] > array_to_sort[j + 1]) {
				temp = array_to_sort[j];
				array_to_sort[j] = array_to_sort[j + 1];
				array_to_sort[j + 1] = temp;
			}
		}
	}
return 0;
}

int function_array_insertion_sort_i(int* array_to_sort, int array_element_count) {
	int j, x = 0;
	for (int i = 1; i < array_element_count; ++i) {
		x = array_to_sort[i];
		j = i;

		while (j > 0 && array_to_sort[j - 1] > x) {
			array_to_sort[j] = array_to_sort[j - 1];
			j = j - 1;
		}
		array_to_sort[j] = x;
	}
}