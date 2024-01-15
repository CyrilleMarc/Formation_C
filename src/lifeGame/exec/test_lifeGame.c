#include <stdlib.h>
#include <time.h>

#include <common/common.h>
#include <lifeGame/lifeGame.h>

int main(int argc, char* argv[])
{
	logger_set_current_level(LOG_DEBUG);
	logger_log(LOG_DEBUG, __FUNCSIG__, argv[0]);

	srand(time(NULL));
	int world[20][20] = { 0 };
	int nb_cell = 0;
	

	nb_cell = init_insert_size_of_world();
	while (nb_cell < 0 || nb_cell > 400) {
		nb_cell = init_insert_size_of_world();
	}
	


}


