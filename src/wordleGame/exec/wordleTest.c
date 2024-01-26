#include <stdio.h>
#include <stdlib.h> //malloc
#include <string.h>
#include <time.h> //rand


int loadFile(const char *filename, char ***wordsListInArray, int *sizeList)
{
    FILE *file = fopen(filename, "r");
    if (NULL == file)
    {
        perror("file not found");
        fclose(file);
        return 1;
    }
    *sizeList = 0;
    char word[6] = {0};
    while (fscanf(file, "%s", word) == 1)
    {
        (*sizeList)++;
    }
    printf("Size list %d words\n", *sizeList);
    *wordsListInArray = (char **)malloc((*sizeList) * sizeof(char *));
    memset(*wordsListInArray, 0, (*sizeList) * sizeof(char*));

    if (NULL == *wordsListInArray)
    {
        perror("Failure, memory not allocated");
        return 1;
    }
    rewind(file);

    for (int i = 0; i < *sizeList; ++i)
    {
        (*wordsListInArray)[i] = (char *)malloc(strlen(word) + 1);
       // memset(*wordsListInArray[i], 0, (strlen(word) + 1));

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

int findRandomWordInList(char **wordsListInArray, int sizeList, char *wordToFind)
{
    int randomNumber = rand() % sizeList;
    strcpy(wordToFind, wordsListInArray[randomNumber]);
    return 0;
}

findNewWordInList(char** matchArray, int* newSizeList, char** newWord)
{
    int randomNumber = rand() % (*newSizeList);
    *newWord = malloc(6 * sizeof(char));
    strcpy(*newWord,matchArray[randomNumber]);
    return 0;
}

int compareWords(const char *wordToFind, const char *propositionWord)
{
    if (strcmp(wordToFind, propositionWord) == 0)
    {
        return 0;
    }
    return 1;
}

int commonLetter = 0;
void scoring(const char *wordToFind, const char *propositionWord, char **bufferTab, int *bufferTabSize)
{
    int commonLetter = 0;
    *bufferTabSize = 0;

    // Allocation mémoire pour bufferTab en fonction du nombre de lettres en commun
    *bufferTab = (char *)malloc(5 * sizeof(char ));
    memset(*bufferTab, 0, 5 * sizeof(char)); // initialise le tableau
    char wordToFindTemp[6] = { 0 };
    strcpy(wordToFindTemp, wordToFind);
    for (int i = 0; i < 5; ++i)
    {
      
        for (int j = 0; j < 5; ++j)
        {
             if (wordToFindTemp[j] == propositionWord[i])
            {
                if (i != j)
                {
                    printf("%d - Common letter : \x1b[32m%c\x1b[0m\n", commonLetter + 1, propositionWord[i]);
                }
                else
                {
                    printf("Good place letter : \x1b[32m%c\x1b[0m\n", wordToFind[j]);
                }
      
                // Allocation mémoire pour chaque lettre en commun
                (*bufferTab)[commonLetter]= propositionWord[i];
                commonLetter++;
                wordToFindTemp[j] = '#';
                break;
            }
        }
    }
    bufferTabSize = commonLetter;
    // Affichage du contenu de bufferTab
    for (int i = 0; i < commonLetter; i++)
    {
        printf("%c\n", (*bufferTab)[i]);
    }
}

int decrease_test_try(int testTry, const char *wordToFind)
{
    testTry--;
    switch (testTry)
    {
    case 1:
        printf("Try remaining : %d\n", testTry);
        return testTry;
    case 0:
        printf("Sorry, you haven't found the word. Right word was %s\n ", wordToFind);
       return testTry;
    default:
        if (testTry > 1)
        {
            printf("tries remaining : %d\n", testTry);
            return testTry;
        }
    }
}



int removeWordOfList(char ***wordsListInArray, int *sizeList, const char *propositionWord)
{
    int i, j, currentIndex = 0;
    for (i = 0; i < (*sizeList); i++)
    {
        if (strcmp((*wordsListInArray)[i], propositionWord) == 0)
        {
            free((*wordsListInArray)[i]);
            currentIndex = i;
           
            for (j = currentIndex; j < (*sizeList) - 1; j++)
            {
                (*wordsListInArray)[j] = (*wordsListInArray)[j + 1];
            }
        }
    }
    for (i = 0; i < (*sizeList) - 1; i++)
    {
        (*wordsListInArray)[i] = (*wordsListInArray)[i + 1];
    }
    (*sizeList)--;

return 0;
}


/*
int isPossible(char*** wordsListInArray, int* sizeList, char* bufferTab, int *bufferTabSize, int *newSizeList, int *goodLetter)
{
    int i, j, k, z = 0;

    for (i = 0; i < 5; i++)
    {
        if (bufferTab[i] != 0)
        {
            (*bufferTabSize)++;
        }
    }

    for (i = 0; i < *sizeList; i++)
    {
        *goodLetter = 0;
        for (j = 0; j < 5; j++)
        {
            for (k = 0; k < 5; k++)
            {
                if ((*wordsListInArray)[i][j] == bufferTab[k] && j != k)
                {
                    (*wordsListInArray)[i][j] = '*';
                    (*goodLetter)++;
                }
            }
        }

        if (*goodLetter == *bufferTabSize)
        {
           printf(" wordsInList-> %s goodLetter->%d, bufferTabSize-> %d\n", (*wordsListInArray)[i], *goodLetter, *bufferTabSize);
           (*newSizeList)++;

        }
        else
        {
            j = i;
            (*wordsListInArray)[i] = NULL;
            free((*wordsListInArray)[i]);
            (*wordsListInArray)[j] = (*wordsListInArray)[j + 1];
            (*sizeList)--;
        }
    }

    printf("New size list-> %d\n", *newSizeList);
    return 0;
}*/


int isPossible(char*** wordsListInArray, int* sizeList, char* bufferTab, int* bufferTabSize, int* newSizeList, int* goodLetter, char*** matchArray)
{
    int i, j, k, z = 0;
    *matchArray = malloc((*sizeList) * sizeof(char*));
    for (i = 0; i < 5; i++)
    {
        if (bufferTab[i] != 0)
        {
            (*bufferTabSize)++;
        }
    }

    for (i = 0; i < *sizeList; i++)
    {
        *goodLetter = 0;
        for (k = 0; k < *bufferTabSize; k++)
        {
            for (j = 0; j < 5; j++)
            {
                if (bufferTab[k] == (*wordsListInArray)[i][j] && j != k)
                {
                    (*goodLetter)++;
                    break;
                }
            }
        }
        if (*goodLetter >= *bufferTabSize)
        {
            (*matchArray)[(*newSizeList)] = (*wordsListInArray)[i];
            (*newSizeList)++;
        }
    }
}

