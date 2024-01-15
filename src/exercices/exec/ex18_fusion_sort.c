#include <stdio.h>

#include <common/common.h>

/*
void merge(int arr[], int left[], int leftSize, int right[], int rightSize)
{
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize)
    {
        if (left[i] < right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    while (i < leftSize)
    {
        arr[k++] = left[i++];
    }

    while (j < rightSize)
    {
        arr[k++] = right[j++];
    }
}*/

int main()
{
    logger_set_current_level(LOG_INFO);
    logger_log(LOG_DEBUG, __FUNCSIG__, "");

/*    int arr[] = {38, 27, 43, 3, 9, 82, 10, 15, 6789, 54, 67, 89, 99, 0, 67};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Tableau avant le tri :\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, size);

    printf("Tableau après le tri :\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");*/

    return 0;
}
/*
void mergeSort(int arr[], int size)
{
    if (size <= 1)
    {
        return;
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++)
    {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);

    merge(arr, left, mid, right, size - mid);
}
*/
//*****************************************
//  int i, j = 0;
//  int* array_left=NULL;
//  int* array_right=NULL;

//  while(array_element_count > 2){
//      if (array_element_count % 2 == 0) {
//          array_left = malloc((array_element_count / 2) * sizeof(int));
//          array_right = malloc((array_element_count / 2) * sizeof(int));
//      }
//      else {
//          array_left = malloc(((array_element_count + 1) / 2) * sizeof(int));
//          array_right = malloc(((array_element_count - 1) / 2) * sizeof(int));
//      }
//      array_element_count = array_element_count / 2;
//  }
//  while(array_element_count < sizeof(array_to_check) / sizeof(int))
//  for (i = 0; i < array_element_count; ++i) {
//      if (i == array_element_count / 2) {
//          array_left[i] = array_to_check[i];
//      }
//      else {
//          array_right[i - array_element_count / 2] = array_to_check[i];
//      }
//  }
//  for (i = 0; i < array_element_count / 2; ++i) {
//      for (j = 0; j < (array_element_count / 2 - 1); ++j) {
//          if (array_left[j] > array_left[j + 1]) {
//              int temp = array_left[j];
//              array_left[j] = array_left[j + 1];
//              array_left[j + 1] = temp;
//          }
//      }
//  }

//  for (i = 0; i < (array_element_count - array_element_count / 2); ++i) {
//      for (j = 0; j < ((array_element_count - array_element_count / 2) - 1); ++j) {
//          if (array_right[j] > array_right[j + 1]) {
//              int temp = array_right[j];
//              array_right[j] = array_right[j + 1];
//              array_right[j + 1] = temp;
//          }
//      }
//  }

//  array_to_check = malloc(array_element_count * sizeof(int));
 

