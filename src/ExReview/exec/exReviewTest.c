#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//#include "ExReview/exReview.h"


int main()
{
	FILE* file = fopen("C:/Users/cyril/Desktop/dataFiles/Session_data.txt", "r");
	if (NULL == file)
	{
		perror("File not found");
		return NULL;
	}
	
	char buffer[10];

	while(fgets(buffer, sizeof(buffer), file) != NULL)
	{
		printf("%s\n", buffer);
	}



	fclose(file);
	
	return 0;
}