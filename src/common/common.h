#pragma once


enum LogLvl { LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL };

void logger_set_current_level(enum LogLvl log_lvl);
void logger_log(enum LogLvl log_lvl, const char* function, const char* msg);