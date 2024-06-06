#pragma once

FILE *openFile(FILE* filename);
int fillFile(const char* word, FILE* file);
int scanFile(int buffer, FILE* file);