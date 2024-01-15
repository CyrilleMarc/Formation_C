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
    printf("La taille de la liste est de %d mots\n", *sizeList);
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
        memset(*wordsListInArray[i], 0, strlen(word) + 1);

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
                    printf("%d - Lettre en commun : \x1b[32m%c\x1b[0m\n", commonLetter + 1, propositionWord[i]);
                }
                else
                {
                    printf("lettre bien placee\n");
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
        printf("essai restant : %d\n", testTry);
        break;
    case 0:
        printf("Vous n'avez plus d'essai, désolé mais vous pouvez rejouer.\nLe mot à trouver était %s\n ", wordToFind);
        break;
    default:
        if (testTry > 1)
        {
            printf("essais restants : %d\n", testTry);
            break;
        }
    }
    return testTry;
}

/*removeWordOfList(char** wordsListInArray, int* sizeList, const char* propositionWord);
isPossible(char* wordToTest, char* bufferTab, int bufferTabSize);
*/

int findBestWordInList(char **wordsListInArray, int sizeList, char *bufferTab, int bufferTabSize, char ***secondArray)
{
    int total = 0;
    for (int i = 0; i < sizeList; i++)
    {
        int validLetter = 0;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < bufferTabSize; k++)
            {
                if (wordsListInArray[i][j] == bufferTab[j])
                {
                    validLetter++;
                }
            }
        }

    }
    printf("\n%d\n", total);
    return 0;
}