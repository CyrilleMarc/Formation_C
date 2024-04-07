#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <common/common.h>
#include <todoList/todoList.h>

int main()
{
    int choice = 0;
    char taskAdded[200] = { 0 };
    char* buffer = NULL;

    while (1)
    {
        printf("******************************\n");
        printf("           TO DO LIST         \n\n");
        printf("[1] Add a task\n");
        printf("[2] Display tasks\n");
        printf("******************************\n");
        scanf("%d", &choice);

        todoListFunction(choice, taskAdded, buffer);
    }
    return 0;
}