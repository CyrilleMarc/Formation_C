#include <stdio.h>

#include <common/common.h>

int main()
{
    logger_set_current_level(LOG_INFO);
    logger_log(LOG_DEBUG, __FUNCSIG__, "");


    int nombres[10] = {0};
    int x = 0;
    int *pn;

    pn = nombres;

    for (x = 0; x < 10; ++x)
    {
        *pn = x + 1;
        ++pn;
    }
    for (x = 0; x < 10; ++x)
    {
        printf("%d, %d\n", x + 1, nombres[x]);
    }
    printf("%p\n", &nombres[0]);
    return 0;
}