
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	return 0;
}

/*
int fibonacci(int n);

int main()
{
	int* tab = NULL;
	int n = 20;
	int i = 0;

	tab = malloc(n * sizeof(int));
	if (NULL == tab)
	{
		printf("memory allocation failure");
		return 1;
	}
	else
		for (i = 0; i < n; i++)
	{
		tab[i] = fibonacci(i);
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", tab[i]);
	}
	free(tab);
	return 0;
}

int fibonacci(int n)
{
	if (n <= 1)
	{
		return n;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}*/

/*

void reloopDown(int n)
{
	if (n >= 0)
	{
		printf("%d ", n);
		reloopDown(n - 1);
	}
}

void main() {

	reloopDown(10);
}*/

//************EXERCICE_1**************************************
/*
void reloopUp(int start, int end, int step);


void main()
{
	reloopUp(2, 140, 3);
}

void reloopUp(int start, int end, int step)
{
	if (start <= end)
	{
		printf("%d ", start);
		start = start + step;
		reloopUp(start, end, step);

	}
}*/

//************EXERCICE_2******************************************

/*
long convertInBase10(long n, int base)
{
	long quotient = n / 10;
	long reste = n % 10;

	if (quotient == 0)
	{
		return reste;
	}
	else
	{
		return convertInBase10(quotient, base) * base + reste;
	}
}

void main()
{
	int n = convertInBase10(137, 11);
	printf("%d ", n);
}*/

//************EXERCICE_3_Algorithme_Tour_de_Hanoi**************************


/*
int iteration = 0;

void deplacer(int n, char depart, char but, char intermediaire)
{
	if (n > 0)
	{
		deplacer(n - 1, depart, intermediaire, but);
		printf("Moove a disc from %c --> %c \n", depart, but);
		deplacer(n - 1, intermediaire, but, depart);
		iteration = iteration + 1;
	}
}
	void main()
	{
		int n = 0;

		printf("Number of discs to moove ? :\n");
		scanf("%d", &n);

		clock_t start = clock();

		deplacer(n, 'A', 'B', 'C');

		clock_t end = clock();

		double totalTime = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("Total execution time: %.2f seconds\n", totalTime);
		printf("Nombre d'iterations: %d\n", iteration);


		return 0;

	}*/

//************EXERCICE_4_Cercles_recursifs*************************

/*
void deuxCercles(int x, int y, int r)
{
	if (r > 10)
	{
		cercle(x, y, r);
		int pr = r / 2;  // pr = petit rayon
		deuxCercles(x + pr, y, pr);
		deuxCercles(x - pr, y, pr);
	}
}*/

//On a les relations suivantes :
// r = h + pr;
// pr = h * sqrt(3) / 2;
// d’où on peut déduire :
// pr = (2 * sqrt(3) – 3) * r = 0.4641 * r;
// h = (4 – 2 * sqrt(3)) * r = 0.5359 * r;

/*
void troisCercles(int x, int y, int r)
{
	if (r > 10)
	{
		cercle(x, y, r);
		// int pr = int((2 * sqrt(3.0) - 3) * r);
		int pr = (int)(0.4641 * r);
		int h = r - pr;
		troisCercles(x-h, y, pr);
		troisCercles(x + h/2, y+pr, pr);
		troisCercles(x + h/2, y-pr, pr);

	}
}*/

//****************EXERCICE_5_Rappel_sur_les_structures*******************

/*
typedef char char15[15];

typedef struct
{
	char15 nom;
	char15 prenom;
} Personne;

void main()
{
	Personne father;
	Personne mother;

	strcpy(father.nom, "MARC");
	strcpy(father.prenom, "Cyrille");
	printf("%s %s\n", father.nom, father.prenom);
	strcpy(mother.nom, "LAURENT");
	strcpy(mother.prenom, "Valerie");
	printf("%s %s\n", mother.nom, mother.prenom);

}*/



/*

typedef struct personne
{
	char name[20];
	int age;
	char gender[10];
	struct personne* partner;

} Personne;

int main()
{
	Personne *man;
	Personne *woman;

	man = malloc(sizeof(Personne));
	if (NULL == man)
	{
		printf("memory allocation failed");
		return 1;
	}

	woman = malloc(sizeof(Personne));
	if (NULL == woman)
	{
		printf("memory allocation failed");
		return 1;
	}

	strcpy(woman->name, "Valerie");
	woman->age = 49;
	strcpy(woman->gender, "female");
	woman->partner = man->name;

	strcpy(man->name, "Cyrille");
	man->age = 48;
	strcpy(man->gender, "male");
	man->partner = woman->name;

	printf("%s-> %d-> %s,  conjoint: %s\n", man->name, man->age, man->gender, man->partner);
	printf("%s-> %d-> %s,  conjoint: %s\n", woman->name, woman->age, woman->gender, woman->partner);
	free(man);
	return 0;
}*/

