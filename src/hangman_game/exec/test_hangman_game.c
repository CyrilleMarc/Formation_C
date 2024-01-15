#include <stdlib.h>
#include <stdio.h>

#include <common/common.h>



int main(int argc, char* argv[])
{
	logger_set_current_level(LOG_DEBUG);
	logger_log(LOG_DEBUG, __FUNCSIG__, argv[0]);

	char word_to_find[6] = "games";
	char letter = "";
	char response[6] = "*****";
	int try = 0;
	int boolWordFound = 0;
	int i = 0;
	int j = 0;

	while (5 > try) {
		printf("Entrez 1 lettre :\n");
		scanf(" %c", &letter);
		for (i = 0; i < 5; ++i) {
			if (letter == word_to_find[i] && response[i] == '*') {
				response[i] = letter;		
			}
		}
		printf("\n");
		try++;
		int total = 5 - try;
		printf("Mot actuel : %s\n", response);
		if (strcmp(response, word_to_find) == 0) {
			printf("Félicitations, vous avez trouvé le mot");
			break;
		}
		printf("\n");
		printf("Il vous reste %d essais\n", total);
	}
}



