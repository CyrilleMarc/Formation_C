#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <time.h>


struct Data 
{
    char prenom[200];
    char nom[200];
};

struct Data user; 

int main()
{

    FILE *sourceFile = fopen("C:/Users/cyril/Desktop/dataFiles/structure_test.txt", "r");
    FILE *destinationFile = fopen("C:/Users/cyril/Desktop/dataFiles/structure_test_sorted.txt", "w");
    if (NULL == sourceFile || NULL == destinationFile)
    {
        lprintf("File not found");
    }
    char person[2048];
    while (fgets(person, sizeof(person), sourceFile) != NULL)
    {
        sscanf(person, "%s %s", user.prenom, user.nom);

        fprintf(destinationFile, "%s, %s\n", user.prenom, user.nom);
    }

    fclose(sourceFile);
    fclose(destinationFile);
    return 0;
}
