#include <common/common.h>
#include <stdio.h>
#include <windows.h>

static const char* level_strings[] = 
{
  "TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"
};

static int log_level = LOG_ERROR;

void logger_set_current_level(enum LogLvl log_lvl)
{
  log_level = log_lvl;
}

void logger_log(enum LogLvl log_lvl, const char* function, const char* msg)
{
  if (log_level <= log_lvl)
  {
    SYSTEMTIME sytem_time = { 0 };
    GetLocalTime(&sytem_time);
    printf("%02d:%02d:%02d:%02d %s %s %s\n", sytem_time.wHour, sytem_time.wMinute, sytem_time.wSecond, sytem_time.wMilliseconds, level_strings[log_lvl], function, msg);
  }
}