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

int scoring(char** wordsListInArray, int* sizeList, int bufferTabSize, const char* wordToFind, char* propositionWord, char **bufferTab)
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
                strcpy(bufferWord2, (wordsListInArray)[i]);
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
        if ((totalScoreInArray != total) && ((*bufferTab)[bufferTabSize] != (wordsListInArray)[i][bufferTabSize]))
        {
            free((wordsListInArray)[i]);
            (*sizeList)--;
            for (j = i; j < *sizeList; j++)
            {
                (wordsListInArray)[j] = (wordsListInArray)[j + 1];
            }
        }
    }
    printf("bufferTabSize->%d\n", bufferTabSize);
    printf("newSizeList ->%d\n", *sizeList);
    printf("TotalScore ->%d\n", totalScoreInArray);
    return 0;
}


void removeWord(int* sizeList, char* propositionWord, char** wordsListInArray)
{
    int i, j = 0;
    int sizeListTemp = sizeList;

    for (i = 0; i < sizeListTemp; i++)
    {
        if (0 == strcmp(wordsListInArray[i], propositionWord))
        {
            free(propositionWord);
            for (j = i; j < sizeListTemp - 1; j++)
            {
                wordsListInArray[j] = wordsListInArray[j + 1];
            }
            wordsListInArray[sizeListTemp - 1] = NULL;
            (*sizeList)--;
            return;
        }
    }
    printf("Warning, word not found");

}
int isPossible(char* ref, char* prop)
{
    int sizeRef = strlen(ref + 1);
    int sizeProp = strlen(prop + 1);
    int i, j = 0;
    for (i = 0; i < sizeRef; i++)
    {
        for (j = 0; j < sizeProp; j++)
        {
            if (ref[i] == prop[j])
            {
                return 1;
            }
        }
    }
    return 0;
}

void cleanWordsListInArray(char** wordsListInArray, int* sizeList, char* propositionWord)
{
    int sizeListTemp = sizeList;
    int i = 0;
    int k = i;
    for (i = 0; i < sizeListTemp; i++)
    {
        if (NULL != wordsListInArray[k])
        {
            if (isPossible(wordsListInArray[k], propositionWord) != 0)
            {
                removeWord(sizeListTemp, propositionWord, wordsListInArray);
            }
            else
            {
                k = i;
            }
        }
    }
}

int testCleanInit(const char* filenameTest, char*** wordsInArrayTest, int* sizeListTest)
{
    char word[6] = { 0 };
    FILE* fileTest = fopen(filenameTest, "r");
        if (NULL == fileTest)
        {
            (printf("File \"%s\" not found\n", filenameTest));
            return -1;
        }
        else
        {
            *sizeListTest = 0;
            while(fscanf(fileTest, "%s", word) == 1)
            {
                (*sizeListTest)++;
            }
        }
    printf("SizeListTest = %d words inside\n", *sizeListTest);
    rewind(fileTest);
    int i, j = 0;
    *wordsInArrayTest = malloc((*sizeListTest) * sizeof(char*));
    memset(*wordsInArrayTest, 0, (*sizeListTest) * sizeof(char*));
    if (NULL == *wordsInArrayTest)
    {
        printf("Memory allocation failure !");
        return 1;
    }
    for (i = 0; i < (*sizeListTest); i++)
    {
        (*wordsInArrayTest)[i] = malloc(6);
        memset((*wordsInArrayTest)[i], 0, 6);
        fscanf(fileTest, "%s", (*wordsInArrayTest)[i]);
        //printf("%s\n", (*wordsInArrayTest)[i]);
    }
    rewind(fileTest);
    return 1;
}

int testClean(char** wordsInArrayTest, int* sizeListTest)
{
    int sizeListFirst = (*sizeListTest);
    int sizeListSecond = 0;
    //printf("sizeListFirst -> %d\n", sizeListFirst);
    int i, j = 0;
    int randomNum = rand() % sizeListFirst;
    //printf("randomNum -> %d\n", randomNum);
    for (i = 0; i < sizeListFirst; i++)
    {
        if(wordsInArrayTest[i] == randomNum)
        free(wordsInArrayTest[i]);
        break;
    }
    sizeListFirst--;
    j = randomNum;
    wordsInArrayTest[j] = wordsInArrayTest[j + 1];
    
    sizeListSecond = sizeListFirst;
    wordsInArrayTest[sizeListSecond] = NULL;
    if (wordsInArrayTest[sizeListSecond] == NULL)
    {
        printf("adress updated\n");
    }
    else
    {
        return -1;
    }
    return 1;
}

int test_WordsInArray(char** wordsInArrayTest, int* sizeListTest)
{
    int i, j, k = 0;
    int score =0;

    char* ref = malloc(6);
    memset(ref, 0, 6);
    char* prop = malloc(6);
    memset(prop, 0, 6);
    if (NULL == ref || NULL == prop)
    {
        return -1;
    }

    /****************Same word test*********************/

    strcpy(ref, wordsInArrayTest[0]); //ADDAX
    strcpy(prop, wordsInArrayTest[0]);//ADDAX

        for (j = 0; j < 5; j++)
        {
            if (ref[j] == prop[j])
            {
               score++;
            }
        }
        if (score < 5)
        {
            return -1;
        }
     /*******************************************/

    /*****************different word test*****/
        strcpy(ref, wordsInArrayTest[5]); // FJORD
        strcpy(prop, wordsInArrayTest[0]); //GUGUS
        score = 0;
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (ref[i] == prop[j])
                    score++;
                    break;
            }
        }
        if (score != 0)
        {
            return -1;
        }
    /*******************************************/

    return 1;
}