#include <stdio.h>
#include <stdlib.h> //malloc
#include <string.h>
#include <time.h> //rand
#include <errno.h>

int loadFile(const char* filename, char*** wordsListInArray, int* sizeList)
{
    FILE* file = fopen(filename, "r");
    if (NULL == file)
    {
        perror("file not found");
        fclose(file);
        return 1;
    }
    *sizeList = 0;
    char word[6] = { 0 };
    while (fscanf(file, "%s", word) == 1)
    {
        (*sizeList)++;
    }

    printf("The size of the list is %d words\n", *sizeList);

    *wordsListInArray = (char**)malloc((*sizeList) * sizeof(char*));
    if (NULL == *wordsListInArray)
    {
        perror("Failure, memory not allocated");
        return 1;
    }

    rewind(file);

    for (int i = 0; i < *sizeList; ++i)
    {
        (*wordsListInArray)[i] = (char*)malloc(strlen(word) + 1);

        if ((*wordsListInArray)[i] == NULL)
        {
            perror("Failure, memory not allocated");
            return 1;
        }
        fscanf(file, "%s", (*wordsListInArray)[i]);
    }
    fclose(file);
    return 0;
}

int findRandomWordInList(char** wordsListInArray, int sizeList, char* wordToFind)
{
    if (sizeList > 0)
    {
        int randomNumber = rand() % sizeList;
        strcpy(wordToFind, wordsListInArray[randomNumber]);
        return 0;
    }
    else
    {
        printf("SizeList is 0\n");
    }
}

int compareWords(const char* wordToFind, const char* propositionWord)
{
    if (strcmp(wordToFind, propositionWord) == 0)
    {
        return 0;
    }
    return 1;
}

int scoring(char*** wordsListInArray, int* sizeList, int bufferTabSize, const char* wordToFind, char* propositionWord, char **bufferTab)
{
    int i, j, k = 0;
    int totalScoreInArray = 0;
    char bufferWord[6] = { 0 };
    char bufferWord2[6] = { 0 };
    int commonLetter = 0;
    int rightLetter = 0;
    int total = 0;

    strcpy(bufferWord, propositionWord);

    *bufferTab = malloc(5 * sizeof(char));
    memset(*bufferTab, 0, 6);
    bufferTabSize = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (wordToFind[i] == bufferWord[j])
            {
                if (i == j)
                {
                    rightLetter += 2;
                    (*bufferTab)[bufferTabSize] = bufferWord[j];
                    bufferWord[j] = '#';
                    bufferTabSize++;
                    break;
                }
                if (i != j)
                {
                    commonLetter++;
                    (*bufferTab)[bufferTabSize] = bufferWord[j];
                    bufferWord[j] = '#';
                    bufferTabSize++;
                    break;
                }
            }
        }
    }
    total = commonLetter + rightLetter;
    printf("total -> %d\n", total);
    printf("bufferTabSize->%d\n", bufferTabSize);

    for (i = 0; i < *sizeList; i++)
    {
        totalScoreInArray = 0;
        commonLetter = 0;
        rightLetter = 0;
        bufferTabSize++;
        for (j = 0; j < 5; j++)
        {
            bufferTabSize = 0;
            for (k = 0; k < 5; k++)
            {
                strcpy(bufferWord2, (*wordsListInArray)[i]);
                if (bufferWord2[j] == propositionWord[k])
                {
                    if (k == j)
                    {
                        rightLetter += 2;
                        bufferWord2[j] = '#';
                        bufferTabSize++;
                        break;
                    }
                    if (k != j)
                    {
                        commonLetter++;
                        bufferWord2[j] = '#';
                        bufferTabSize++;
                        break;
                    }
                }
            }
        }
        totalScoreInArray = commonLetter + rightLetter;
        if ((totalScoreInArray != total) && ((*bufferTab)[bufferTabSize] != (*wordsListInArray)[i][bufferTabSize]))
        {
            free((*wordsListInArray)[i]);
            (*sizeList)--;
            for (j = i; j < *sizeList; j++)
            {
                (*wordsListInArray)[j] = (*wordsListInArray)[j + 1];
            }
        }
    }
     printf("bufferTabSize->%d\n", bufferTabSize);
    printf("newSizeList ->%d\n", *sizeList);
    printf("TotalScore ->%d\n", totalScoreInArray);
    return 0;
}



/*
int scoring(const char* wordToFind, const char* propositionWord, char** bufferTab, int bufferTabSize)
{
    int i, j, k , rightPlace = 0;
    int rightLetter = 0;
    int initialValue = -1;
    char* wordToFindTemp = malloc(6);
    strcpy(wordToFindTemp, wordToFind);
    *bufferTab = (char*)malloc(5 * sizeof(char));

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if ((propositionWord[i] == wordToFindTemp[i]) && ((*bufferTab)[i] = initialValue))
            {
                (*bufferTab)[i] = wordToFindTemp[i];
                rightPlace++;
                break;
            }
            if ((propositionWord[i] == wordToFindTemp[j]) && ((*bufferTab)[i] = initialValue))
            {
                (*bufferTab)[i] = wordToFindTemp[j];
                rightLetter++;
                break;
            }
            else
            {
                (*bufferTab)[i] = initialValue;
            }
        }
        printf("%c ", (*bufferTab)[i]);
    }
    printf("%\n");
    bufferTabSize = rightLetter;
    return bufferTabSize;
}

int isPossible(char*** wordsListInArray, int* sizeList, char* bufferTab, int bufferTabSize)
{
    int i, j, k = 0;
    int rightLetter = 0;
    int newSizeList = 0;
    char bufTemp[6] = { 0 };
    
    for (i = 0; i < *sizeList; i++)
    {
        rightLetter = 0;

        for (j = 0; j < 5; j++)
        {
            for (k = 0; k < 5; k++)
            {
                if (bufferTab[k] == (*wordsListInArray)[i][j] && j != k)
                {
                    rightLetter++;
                    break;
                }
            }
        }
        if (rightLetter >= bufferTabSize)
        {
            (*wordsListInArray)[newSizeList] = (*wordsListInArray)[i];
            printf("%s\n", (*wordsListInArray)[newSizeList]);
            newSizeList++;
        }
        else
        {
            free((*wordsListInArray)[i]);
        }
    }
    *sizeList = newSizeList;
    printf("%d\n", newSizeList);
}
*/