#include <common/common.h>
#include <stdio.h>

void show_all_log_levels()
{
  logger_log(LOG_DEBUG, __FUNCSIG__, "  Show LOG_DEBUG");
  logger_log(LOG_INFO, __FUNCSIG__, "  Show LOG_INFO");
  logger_log(LOG_WARN, __FUNCSIG__, "  Show LOG_WARN");
  logger_log(LOG_ERROR, __FUNCSIG__, "  Show LOG_ERROR");
  logger_log(LOG_FATAL, __FUNCSIG__, "  Show LOG_FATAL");
}

int main(int argc, char* argv[])
{
  logger_set_current_level(LOG_DEBUG);
  logger_log(LOG_DEBUG, __FUNCSIG__, argv[0]);
  printf("LOG_DEBUG\n");
  show_all_log_levels();
  logger_set_current_level(LOG_INFO);
  printf("LOG_INFO\n");
  show_all_log_levels();
  logger_set_current_level(LOG_WARN);
  printf("LOG_WARN\n");
  show_all_log_levels();
  logger_set_current_level(LOG_ERROR);
  printf("LOG_ERROR\n");
  show_all_log_levels();
  logger_set_current_level(LOG_FATAL);
  printf("LOG_FATAL\n");
  show_all_log_levels();

}