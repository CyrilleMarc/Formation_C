#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>

#include "common/common.h"


int main(int argc, char* argv[])
{
	logger_set_current_level(LOG_DEBUG);
	logger_log(LOG_DEBUG, __FUNCSIG__, argv[0]);

	printf("******************WORDLE********************\n");

	const char* fileName = "C:/Users/cyril/Desktop/dataFiles/wordToFind.txt";
	char **wordArray= NULL;
	int sizeList = NULL;

	loadFile(fileName, &wordArray, &sizeList);
	

	return 0;
}