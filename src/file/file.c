#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "file.h" 
#include "common/common.h"

char *convert_file(const char* fileName, const char *fileName2)
{
	FILE* fileIn = fopen(fileName, "r");
	FILE* fileOut = fopen(fileName2, "w");
	if ((NULL == fileIn) || (NULL == fileOut))
	{
		logger_log(LOG_DEBUG, __FUNCSIG__, "File not found\n");
		return NULL;
	}

	const char *token = "";
	char token2 = "";
	do {
		token = fgetc(fileIn);
		if (token = "\n")
		{
			token2 = strcpy(token, "");
		}
		printf("%c", token2);
		fprintf(fileOut, "%c", token2);
	}
	while (token != EOF);
	

	fclose(fileIn);
	fclose(fileOut);

}
	

