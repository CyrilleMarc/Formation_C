#include <stdio.h>
#include <stdlib.h>

#include "fichier_binaire/fichier_binaire.h"
#include "common/common.h"


int main(int argc, int** argv)
{
	logger_set_current_level(LOG_DEBUG);
	logger_log(LOG_DEBUG, __FUNCSIG__, argv[0]);

	const char* fileName = "C:/Users/cyril/Desktop/dataFiles/binatyFile.bin";
	const char* content = "Cyrille";
	int element_count = 1;

	store_binary_file(fileName, content, element_count);
	display_binary_data_in_file(fileName, content, element_count);
	printf("\n");
	printf("My name is %s", content);
    return 0;
}
