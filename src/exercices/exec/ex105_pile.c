#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int number;
    int* back ;
} Pile;

Pile* initStack(int* pile)
{
    Pile* newPile = malloc(sizeof(Pile));
    if (NULL == newPile)
    {
        printf("Memory allocation failure\n");
        return NULL;
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            newPile->number = i;
            printf("%d ", newPile->number);

        }
        printf("\nPile initialised successfully\n");
        return newPile;
    }
}

int main()
{
    int choix = 0;
    Pile* pile = NULL;

    printf("GESTION D'UNE PILE\n");
    printf("0 - Fin\n");
    printf("1 - Creation d'une pile\n");
    printf("votre choix ?\n");
    scanf("%d", &choix);

    switch (choix)
    {
    case(0):
        break;
    case(1):
        pile = initStack(pile);
        break;
    }
    return 0;
}