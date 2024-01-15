#include <stdio.h>
#include <stdlib.h>


/*int main()
{
	int tab[10] = { 1, 2, 5, 8, 12, 45, 89, 110, 200, 666 };

	FILE* file = fopen("C:/Users/cyril/Desktop/datafiles/sourceFile.txt", "w");
	if (NULL == file)
	{
		perror("C:/Users/cyril/Desktop/datafiles/sourceFile.txt");
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			fprintf(file, "%d\n", tab[i]);
		}
	}
	fclose(file);
	return 0;
}*/
//***********SOLUTION************

/*int main()
{
	FILE* f;
	char s[] = "Bonjour";
	f = fopen("bonjour.txt", "wb");
	if (f != NULL)
	{
		fwrite(s, sizeof(char), strlen(s), f);
		fclose(f);
	}
	else
		perror("bonjour.txt");
	return 0;
}*/

int main()
{
	FILE* f;
	char s[] = "Bonjour";
	f = fopen("C:/Users/cyril/Desktop/dataFiles/bonjour.txt", "wb");
	if (f != NULL)
	{
		fwrite(s, sizeof(char), strlen(s), f);
		fclose(f);
	}
	else 
	{
		perror("bonjour.txt");
	}
	return 0;
}

/*int main()
{
	int number = 0;
	FILE* file = fopen("C:/Users/cyril/Desktop/dataFiles/sourceFile.txt", "r");
	if (NULL == file)
	{
		perror("C:/Users/cyril/Desktop/dataFiles/sourceFile.txt");
	}
	else
	{
		while (fscanf(file, "%d", &number) == 1)
		{
			printf("%d\n", number);
		}
		
	}
	fclose(file);
	return 0;
}*/

/*
int main()
{
	char nameFile[256];
	char character;
	int size = 0;

	printf("%s", "Entrez le nom du fichier avec son extention (ex fichier.txt) :\n");
	scanf("%s", nameFile);
	char fileAddress[300];
	sprintf(fileAddress, "C:/Users/cyril/Desktop/dataFiles/%s", nameFile);

	FILE* file = fopen(fileAddress, "r");
	if (NULL == file)
	{
		printf("Fichier introuvable");
	}
	else
	{
		rewind(file);
		while (fscanf(file, "%c", &character) != EOF)
		{
			size++;
		}
		if (size < 1000)
		{
			printf("Taille du fichier : %d octets", size);
		}
		else
		{
			float kilo_size = size / 1000;
			printf("Taille du fichier : %.1f ko", kilo_size);
		}
	}
	fclose(file);
	return 0;
}*/