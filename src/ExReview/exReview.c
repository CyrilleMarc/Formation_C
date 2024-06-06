#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ExReview/exReview.h"



FILE *openFile(FILE* filename)
{
	FILE* file = fopen(filename, "a");
	if (NULL == file)
	{
		return NULL;
	}
	return file;
}

int fillFile(const char* word, FILE* file)
{
	if (EOF == fputs(word, file))
	{
		return 0;
	}
	fputs("\n", file);
	return 1;
	
}
int scanFile(int buffer, FILE* file)
{
	fscanf(file, "%s");

	return 0;
 }
