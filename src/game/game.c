#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>

#include "common/common.h"

int loadFile(const char* fileName, char*** wordArray, int* sizeList)
{
    char word[6] = { 0 };
    int i = 0;
    FILE* file = fopen(fileName, "r");
    if (NULL == file)
    {
        logger_log(LOG_DEBUG, __FUNCSIG__, "file not found");
        return 1;
    }
    else
    {
        while (fscanf(file, "%s", word) == 1)
        {
            (*sizeList)++;
        }
    }
    rewind(file);
    *wordArray = malloc((*sizeList) * sizeof(char*));
    if (NULL == *wordArray)
    {
        logger_log(LOG_DEBUG, __FUNCSIG__, "Memory allocation failed");
        return 1;
    }
    else
    {
        for (i = 0; i < *sizeList; ++i)
        {
            (*wordArray)[i] = malloc(6 * sizeof(char));
            if (NULL == (*wordArray)[i])
            {
                logger_log(LOG_DEBUG, __FUNCSIG__, "Memory allocation failed");
                return 1;
            }
            fscanf(file, "%s", (*wordArray)[i]);
        }
    }
    fclose(file);
    return 0;
}