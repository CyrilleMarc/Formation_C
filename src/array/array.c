#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <Common/Common.h>
#include <array/array.h>

void array_init_with_random_value_i(int** array_to_malloc, int array_element_count, int max_value)
{
    *array_to_malloc = (int*)malloc(array_element_count * sizeof(int));
    if (NULL == *array_to_malloc ) {
        logger_log(LOG_DEBUG, __FUNCSIG__, "Failed memory allocation\n");
        return;
    }
    srand(time(NULL));

    for (int i = 0; i < array_element_count; ++i) {
        (*array_to_malloc)[i] = rand() % (max_value + 1);
       
    }
   
}

int array_check_sorted_i(int* array_to_check, int array_element_count)
{
    for (int j = 0; j < array_element_count - 1; ++j) {
        if (array_to_check[j] < array_to_check[j + 1]) {
            logger_log(LOG_DEBUG, __FUNCSIG__, "array is sorted\n");
            return 1;
        }
    }
    logger_log(LOG_DEBUG, __FUNCSIG__, "Array is not sorted\n");
    return 0;
}

void array_bubble_sort_i(int* array_to_check, int array_element_count)
{
    int temp = 0;
    int i, j = 0;

    for (i = 0; i < array_element_count; i++) {
        for (j = 0; j < array_element_count - 1; j++) {
            if (array_to_check[j] > array_to_check[j + 1]) {
                temp = array_to_check[j];
                array_to_check[j] = array_to_check[j + 1];
                array_to_check[j + 1] = temp;
            }
        }
    }
}

void array_fusion_sort_i(int* array_to_check, int array_element_count) {
    if (array_element_count <= 1) {
        return;
    }

    int i, j = 0;
    int mid = array_element_count / 2;
    int* array_left = malloc(mid * sizeof(int));
    if (NULL == array_left) {
        logger_log(LOG_FATAL, __FUNCSIG__, "Malloc array_left failed");
        return;
    }
    int* array_right = malloc((array_element_count - mid) * sizeof(int));
    if (NULL == array_right) {
        logger_log(LOG_FATAL, __FUNCSIG__, "Malloc array_right failed");
        return;
    }

    for (i = 0; i < mid; ++i) {
        array_left[i] = array_to_check[i];
    }

    for (i = mid; i < array_element_count; ++i) {
        array_right[i - mid] = array_to_check[i];
    }

    array_fusion_sort_i(array_left, mid);
    array_fusion_sort_i(array_right, array_element_count - mid);

    merge_array_left_and_array_right_i(array_to_check, array_left, mid, array_right, (array_element_count - mid));
}

void merge_array_left_and_array_right_i(int *arr, int *left, int leftSize, int *right, int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] < right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }

    while (i < leftSize) {
        arr[k++] = left[i++];
    }

    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

void array_insertion_sort_i(int* array_to_check, int array_element_count) {
    int x, j = 0;

    for (int i = 0; i < array_element_count; ++i)
    {

        x = array_to_check[i];
        j = i;

        while (j > 0 && array_to_check[j - 1] > x)
        {
            array_to_check[j] = array_to_check[j - 1];
            j = j - 1;
        }
        array_to_check[j] = x;
    }

}

void array_quick_sort_i(int* array_to_check, int array_element_count)
{
    if (array_element_count <= 1)
    {
        return;
    }
    int pivot = array_to_check[array_element_count - 1];
    int i = -1;

    for (int j = 0; j < array_element_count - 1; ++j)
    {
        if (array_to_check[j] < pivot)
        {
            i++;
            int temp = array_to_check[i];
            array_to_check[i] = array_to_check[j];
            array_to_check[j] = temp;
        }
    }
    int temp = array_to_check[i + 1];
    array_to_check[i + 1] = array_to_check[array_element_count - 1];
    array_to_check[array_element_count - 1] = temp;

    array_quick_sort_i(array_to_check, i + 1);
    array_quick_sort_i(array_to_check + i + 2, array_element_count - i - 2);

}