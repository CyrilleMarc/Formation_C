#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#include <common/common.h>

/***************THE GAME OF THE LIFE*******************/


int init_insert_size_of_world() {
	int number_of_case = 0;
	printf("Enter a number of living entities between 1 and 400 : \n");
	scanf("%d", &number_of_case);
	return number_of_case;
}

/*
int random_number(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

int init_number_of_one(int world[20][20]) {
	int i = 0;
	int j = 0;
	int num_one = 0;

	for (i = 0; i < 20; ++i) {
		for (j = 0; j < 20; ++j) {
			if (world[i][j] == 1) {
				num_one++;
			}
		}
	}
	return num_one;
}

void display_world(int world[20][20]) {
	system("cls"); // clear the terminal
	int i = 0;
	int j = 0;
	printf("***********************************\n");

	for (i = 0; i < 20; ++i) {
		for (j = 0; j < 20; ++j) {
			if (world[i][j] == 1) {
				printf("|x");
			}
			else {
				printf("| ");
			}
		}
		printf("|n");
		printf("********************************\n");
	}
	printf("Nombre de cellules vivantes %d", init_of_number_one(world));

}

int copy_world(int array1[20][20], int array2[20][20]) {
	int i = 0;
	int j = 0;

	for (i = 0; i < 20; ++i){
		for(j = 0; j < 20; ++j){
			array1[i][j] = array2[i][j];
		}
	}
	return 1;
}

int neighbour_number(int world[20][20], int i, int j) {
	int neighbour_total = 0;
	i = 0;
	j = 0;

			//Nord
			if (i > 0 && world[i - 1][j] == 1) {
				neighbour_total++;
			}
			//Sud
			if (i < 19 && world[i + 1][j] == 1) {
				neighbour_total++;
			}
			//Ouest
			if (j > 0 && world[i][j - 1] == 1) {
				neighbour_total++;
			}
			//Est
			if (j < 19 && world[i][j + 1] == 1) {
				neighbour_total++;
			}
			//Nord Ouest
			if (i > 0 && j > 0 && world[i -1][j- 1] == 1) {
				neighbour_total++;
			}
			//Sud Ouest
			if (i < 19 && j > 0 && world[i + 1][j - 1] == 1) {
				neighbour_total++;
			}
			//Sud Est
			if (i < 19 && j < 19 && world[i + 1][j + 1] == 1) {
				neighbour_total++;
			}
			//Nord Est
			if (i > 0 && j < 19 && world[i - 1][j + 1] == 1) {
				neighbour_total++;
			}
			return neighbour_total;
}
*/