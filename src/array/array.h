#pragma once

void array_init_with_random_value_i(int** array_to_malloc, int array_element_count,int max_value);

void array_bubble_sort_i(int* array_to_check, int array_element_count);
void array_fusion_sort_i(int* array_to_check, int array_element_count);
void merge_array_left_and_array_right_i(int *arr, int *left, int leftSize, int *right, int rightSize);
void array_insertion_sort_i(int* array_to_check, int array_element_count);
void array_quick_sort_i(int* array_to_check, int array_element_count);


//return 0!= if sorted
int array_check_sorted_i(int* array_to_check, int array_element_count);


