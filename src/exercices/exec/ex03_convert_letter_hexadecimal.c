#include <stdio.h>

#include <common/common.h>
int main()
{
    logger_set_current_level(LOG_INFO);
    logger_log(LOG_DEBUG, __FUNCSIG__, "");

    char letter = 'A';

    for (letter = 'A'; letter <= 'Z'; ++letter)
    {
        printf("caractère = %c\n", letter);
        printf("code = %d\n", letter);
        printf("code hexadécimal = %x\n", letter);
    }
}