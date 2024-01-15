
#include <stdio.h>

#include <common/common.h>

int exchange(int *num1, int *num2);

int main()
{
    logger_set_current_level(LOG_INFO);
    logger_log(LOG_DEBUG, __FUNCSIG__, "");

    int num1 = 0;
    int num2 = 0;

    printf("Saisissez un entier: \n");
    scanf("%d", &num1);
    printf("Saisissez un 2ème entier: \n");
    scanf("%d", &num2);
    printf("num1 = %d et num2 = %d\n", num1, num2);

    int result = exchange(&num1, &num2);
    if (result == 0)
    {
        printf("Après inversion\n");
        printf("num1 = %d\n", num1);
        printf("num2 = %d\n", num2);
        logger_log(LOG_INFO, __FUNCSIG__, "function exchange successfully executed");
    }
    return 0;
}

int exchange(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    return 0;
}