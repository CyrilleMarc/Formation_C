#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <common/common.h>
#define MAX_VALUE 1024

int sortTab(int* tab, int size);

int main()
{
    logger_set_current_level(LOG_INFO);
    logger_log(LOG_DEBUG, __FUNCSIG__, "");

    int *tab = NULL;
    int n = 6;
    int i = 0;
    srand((unsigned int)time(NULL));

    tab = malloc(n * sizeof(int));
    if (NULL == tab)
    {
        logger_log(LOG_DEBUG, __FUNCSIG__, "Memory allocation failed");
        free(tab);
        return -1;
    }

    while(i < n)
    {
        tab[i] = rand() % MAX_VALUE;
        printf("%d ", tab[i]);
        i++;
    }
    printf("\n*************************\n");

    sortTab(tab, n);
    free(tab);

    return 0;
}

int sortTab(int* tab, int size)
{
    int i, j = 0;
    int temp = 0;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
    for (int k = 0; k < size; k++)
    {
        printf("%d ", tab[k]);
    }
}