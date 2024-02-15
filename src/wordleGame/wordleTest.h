#pragma once

int testCleanInit(const char* filenameTest, char** wordsInArrayTest, int* sizeListTest);
int testClean(char** wordsInArrayTest, int* sizeListTest);
int test_WordsInArray(char** wordsInArrayTest, int* sizeListTest);

int loadFile(const char* filename, char*** wordsListInArray, int* sizeList);
int findRandomWordInList(char** wordsListInArray, int sizeList, char* wordToFind);
int compareWords(const char* wordToFind, const char* propositionWord);
int scoring(char*** wordsListInArray, int* sizeList, int bufferTabSize, const char* wordToFind, const char* propositionWord, char **bufferTab);
void cleanWordsListInArray(char** wordsListInArray, int* sizeList, char* propositionWord);
int isPossible(char* ref, char* prop);
