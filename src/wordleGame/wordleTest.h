#pragma once

int loadFile(const char* filename, char*** wordsListInArray, int* sizeList);
int findRandomWordInList(char** wordsListInArray, int sizeList, char* wordToFind);
int compareWords(const char* wordToFind, const char* propositionWord);
int scoring(char*** wordsListInArray, int* sizeList, int bufferTabSize, const char* wordToFind, const char* propositionWord, char **bufferTab);

