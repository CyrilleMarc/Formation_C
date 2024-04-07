#include <stdlib.h>

#include <common/common.h>




int main(int argc, char* argv[])
{
  logger_set_current_level(LOG_DEBUG);
  logger_log(LOG_DEBUG, __FUNCSIG__, argv[0]);
  
}