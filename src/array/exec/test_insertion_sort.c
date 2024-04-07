#include <stdio.h>

#include <common/common.h>
#include <array/array.h>

int main(int argc, char* argv[])
{
    logger_set_current_level(LOG_DEBUG);
    logger_log(LOG_DEBUG, __FUNCSIG__, argv[0]);

    int* array_to_sort = NULL;
    int array_to_sort_size = 1024;
    int max_value = 256;

    array_init_with_random_value_i(&array_to_sort, array_to_sort_size, max_value);

    array_insertion_sort_i(array_to_sort, array_to_sort_size);

    if (array_check_sorted_i(array_to_sort, array_to_sort_size))
    {
        logger_log(LOG_INFO, __FUNCSIG__, "Array is sorted");
        return 0;
    }
    else
    {
        logger_log(LOG_ERROR, __FUNCSIG__, "Array is not sorted");
        return 1;
    }

}

