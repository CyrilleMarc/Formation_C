#include <stdio.h>

#include <common/common.h>

int multiply(int *num1, int *num2);

int main()
{

    logger_set_current_level(LOG_INFO);
    logger_log(LOG_DEBUG, __FUNCSIG__, "");


    int num1 = 0;
    int num2 = 0;
    int result = 0;

    printf("Saisissez un entier:\n");
    scanf("%d", &num1);
    printf("Saisissez un entier:\n");
    scanf("%d", &num2);


    result = multiply(&num1, &num2);
    if (multiply)
    {
        printf("Resultat : %d\n", result);
        logger_log(LOG_INFO, __FUNCSIG__, "function multiply successfully executed");
    }
    return 0;
}

int multiply(int *num1, int *num2)
{
    int result = *num1 * *num2;
    return result;
}