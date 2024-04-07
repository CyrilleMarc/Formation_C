#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <common/common.h>
#include <todoList/todoList.h>

int todoListFunction(int choice, char* taskAdded, char* buffer)
{
    FILE* todoListFile = NULL;
    while (1)
    {
        switch (choice)
        {
        case 1:
            printf("Please enter a task\n");
            getchar();
            fgets(taskAdded, 200, stdin);
            todoListFile = fopen("todoList.txt", "a");
            if (NULL == todoListFile)
            {
                printf("file not found\n");
            }
            else
            {
                fprintf(todoListFile, "%s", taskAdded);
                fclose(todoListFile);
            }

            break;

        case 2:

            todoListFile = fopen("todoList.txt", "r");
            if (NULL == todoListFile)
            {
                printf("File not found");
            }
            else
            {
                int i = 1;
                char line[256];

                while (fgets(line, sizeof(line), todoListFile) != NULL)
                {
                    printf("Task %d: %s", i, line);
                    i++;
                }
                fclose(todoListFile);
            }
            break;

        case 3:

            printf("choice 3");
            break;

        default:
            printf("This choice is not authorized\n");
            break;
        }
        choice = 0;
    }
    return 0;
}