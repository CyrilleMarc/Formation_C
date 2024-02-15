
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "wordleGame/wordleTest.h"
#include "wordleTest.h"

int main()
{
    //***************tests unitaires************************
    int sizeListTest = 0;
    char** wordsInArrayTest = NULL;
    char randomWord[6] = { 0 };
    const char* filenameTest = "C:/Users/cyril/Desktop/archi_cmake/Formation_C/third_party/fichiers/listeTest.txt";
    srand(time(NULL));
    if (testCleanInit(filenameTest, &wordsInArrayTest, &sizeListTest) == 1)
    {
        printf("1 - testCleanInit [OK]\n");
    }
    else
    {
        printf("1 - testCleanInit [KO]\n");
        exit(EXIT_FAILURE);
    }
    if (testClean(wordsInArrayTest, &sizeListTest) == 1)
    {
        printf("2 - testClean [OK]\n");
    }
    else
    {
        printf("Memory adress failure\n");
        printf("1 - testCleanInit [KO]\n");
        exit(EXIT_FAILURE);
    }
    if (1 == test_WordsInArray(wordsInArrayTest, &sizeListTest))
    {
        printf("3 - test_WordsInArray [OK]\n");
    }
    else
    {
        printf("3 - test_WordsInArray [KO]\n");
        exit(EXIT_FAILURE);
    }
    //***************Fin tests unitaires********************

    
    const char* filename = "C:/Users/cyril/Desktop/archi_cmake/Formation_C/third_party/fichiers/liste.txt";
    //const char* filename = "C:/Users/cyrille.SGX0/Desktop/code/Formation_C/third_party/fichiers/liste.txt";
    char** wordsListInArray = NULL;
    int sizeList = 0;
    char word[6] = { 0 };
    char wordToFind[6] = { 0 };
    char propositionWord[6] = { 0 };
    int testTry = 5;
    int comparisonResult = 1;
    int bufferTabSize = 0;
    char bufTemp[6] = { 0 };
    char *bufferTab = NULL;

    printf("Nombre d'essais : %d\n", testTry);

    srand(time(NULL));

    if (loadFile(filename, &wordsListInArray, &sizeList) == 0)
    {
        printf("file \"%s\" found\n", filename);
    }
    else
    {
        perror("Failure, file not loaded");
        return 1;
    }

    findRandomWordInList(wordsListInArray, sizeList, wordToFind);
    printf("Word to find => %s\n", wordToFind);

    
        while (comparisonResult != 0)
        {
            
            findRandomWordInList(wordsListInArray, sizeList, propositionWord);
            printf("Proposition word => %s\n", propositionWord);

            comparisonResult = compareWords(wordToFind, propositionWord);
            if (comparisonResult == 0)
            {
                printf("Bravo , you have found the right word : %s\n", wordToFind);
            }
            else
            {
                cleanWordsListInArray(wordsListInArray, &sizeList, propositionWord);
                scoring(wordsListInArray, &sizeList, bufferTabSize, wordToFind, propositionWord, &bufferTab);
                findRandomWordInList(wordsListInArray, sizeList, propositionWord);
                compareWords(wordToFind, propositionWord);

                testTry--;
                printf("Tries remaining %d\n", testTry);

                if (testTry == 0)
                {
                    break;
                }
            }
        }
        

     
        for (int i = 0; i < sizeList; i++)
        {
            free(wordsListInArray[i]);
        }
        free(wordsListInArray);
        return 0;
}