
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "wordleGame/wordleTest.h"
#include "wordleTest.h"

int main()
{
    char **wordsListInArray = NULL;
    int sizeList = 0;    
    //const char *filename = "C:/Users/cyril/Desktop/archi_cmake/Formation_C/third_party/fichiers/liste.txt";
    const char* filename = "C:/Users/cyrille.SGX0/Desktop/code/Formation_C/third_party/fichiers/liste.txt";
    char wordToFind[6] = {0};
    char wordToTest[6] = { 0 };
    char propositionWord[6] = {0};
    char word[6] = {0};
    int testTry = 5;
    char *bufferTab = NULL;
    char ***matchArray = NULL;
    int *bufferTabSize = NULL;
    int* newSizeList = NULL;
    int* goodLetter = NULL;

    printf("Nombre d'essais : %d\n", testTry);

    //srand(time(NULL));

    if (loadFile(filename, &wordsListInArray, &sizeList) == 0)
    {
        findRandomWordInList(wordsListInArray, sizeList, wordToFind);
        strcpy(wordToFind, "ADDAX");
        printf("The word to find : %s\n", wordToFind);

        findRandomWordInList(wordsListInArray, sizeList, propositionWord);
        strcpy(propositionWord, "AGADA");
        printf("Player proposition : %s\n", propositionWord);
    }
    else
    {
        perror("Failure, file not loaded");
        return 1;
    }

    int FirstResult = compareWords(wordToFind, propositionWord);
    if (FirstResult == 0)
    {
        printf("\x1b[32mBravo, you found the good word !!!\x1b[0m\n");
        return 0;
    }
    else
    {
        scoring(wordToFind, propositionWord, &bufferTab, &bufferTabSize);
    }
    removeWordOfList(&wordsListInArray, &sizeList, propositionWord);
    //isPossible(&wordsListInArray, &sizeList, bufferTab, bufferTabSize, &newSizeList, &goodLetter);
    isPossible(&wordsListInArray, &sizeList, bufferTab, &bufferTabSize, &newSizeList, &goodLetter, &matchArray);
    decrease_test_try(testTry, wordToFind);
    
    // free(wordsListInArray);
    // free(matchArray)
    // free(bufferTab);
    return 0;
}
