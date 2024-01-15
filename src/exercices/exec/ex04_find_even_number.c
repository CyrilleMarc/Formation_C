
#include <stdio.h>

#include <common/common.h>

int isEvenNumber(int *num);
int main()
{
    logger_set_current_level(LOG_INFO);
    logger_log(LOG_DEBUG, __FUNCSIG__, "");

    int num = 0;

    printf("Saisissez un entier: ");
    scanf("%d", &num);

    int ok = isEvenNumber(&num);
    {
        if (ok == 2)
        {
            printf("num %d is even\n ", num);
            logger_log(LOG_INFO, __FUNCSIG__, "function isEvenNumber successfully executed");
        }
        else
        {
            printf("num %d is odd\n ", num);
            logger_log(LOG_INFO, __FUNCSIG__, "function isEvenNumber successfully executed");
        }
    }
    return 0;
}

int isEvenNumber(int *num)
{
    int result = *num % 2;
    if (!result)
    {
        return 2;
    }
}