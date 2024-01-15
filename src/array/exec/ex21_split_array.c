#include <stdio.h>
#include <stdlib.h>

#include <common/common.h>

int main()
{
    logger_set_current_level(LOG_INFO);
    logger_log(LOG_DEBUG, __FUNCSIG__, "");

    int *originalArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Exemple de tableau de pointeurs
    int originalSize = sizeof(originalArray) / sizeof(originalArray[0]);

    // Calcul de la taille des nouveaux tableaux
    int newSize = originalSize / 2;

    // Allouer de la mémoire pour les deux nouveaux tableaux
    int **newArray1 = (int **)malloc(newSize * sizeof(int *));
    int **newArray2 = (int **)malloc(newSize * sizeof(int *));

    // Copier les pointeurs dans les deux nouveaux tableaux
    for (int i = 0; i < newSize; i++)
    {
        newArray1[i] = originalArray[i];
        newArray2[i] = originalArray[i + newSize];
    }

    printf("Tableau 1 :\n");
    for (int i = 0; i < newSize; i++)
    {
        printf("%d ", *newArray1[i]);
    }
    printf("\n");

    printf("Tableau 2 :\n");
    for (int i = 0; i < newSize; i++)
    {
        printf("%d ", *newArray2[i]);
    }
    printf("\n");

    // Libérer la mémoire allouée pour les nouveaux tableaux
    free(newArray1);
    free(newArray2);

    return 0;
}
