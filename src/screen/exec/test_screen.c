#include <stdio.h>
#include <stdlib.h>

#include "common/common.h"

int main(int argc, int* argv)
{
	logger_set_current_level(LOG_DEBUG);
	logger_log(LOG_DEBUG, __FUNCSIG__, "");
}