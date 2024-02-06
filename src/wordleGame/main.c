
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "wordleGame/wordleTest.h"
#include "wordleTest.h"

int main()
{
    const char* filename = "C:/Users/cyril/Desktop/archi_cmake/Formation_C/third_party/fichiers/liste.txt";
    // const char* filename = "C:/Users/cyrille.SGX0/Desktop/code/Formation_C/third_party/fichiers/liste.txt";
    char** wordsListInArray = NULL;
    int sizeList = 0;
    char word[6] = { 0 };
    char wordToFind[6] = { 0 };
    char propositionWord[6] = { 0 };
    int testTry = 15;
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
                    scoring(&wordsListInArray, &sizeList, bufferTabSize, wordToFind, propositionWord, &bufferTab);
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
        //free(bufferTab); 
}