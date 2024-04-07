#include <stdlib.h>
#include <stdio.h>

#include <common/common.h>
#include <file/file.h>



int main()
{
    logger_set_current_level(LOG_DEBUG);
    logger_log(LOG_DEBUG, __FUNCSIG__, "");

    const char *fileName = "C:/Users/cyril/Desktop/dataFiles/wordList.txt";
    const char* fileName2 = "C:/Users/cyril/Desktop/dataFiles/wordList.csv";

   convert_file(fileName, fileName2);
    return 0;
}
