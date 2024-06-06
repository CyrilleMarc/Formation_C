#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "trees/trees.h"
#include <common/common.h>

int main() {
    int data = 100;
    int i, size = 0;
    int numLeftBlack = 0;
    int numRightBlack = 0;
    int memoryMalloc = 0;
    int totalNode = 0;
    int numOfNode = 45;
    int newData[] = { 45, 39, 63, 199, 23, 967 };
    size = sizeof(newData) / sizeof(int);

    Node* root = init_node(&data, &memoryMalloc);

    logger_set_current_level(LOG_DEBUG);
    logger_log(LOG_DEBUG, __FUNCSIG__, "");

    if (root != NULL) {
        printf("Root initialized successfully\n");
        printf("root data = %d\n", *(root->data));
        if (0 == root->color) {
            printf("New root color: BLACK\n");
        }
        if (1 == root->color) {
            printf("New node color: RED\n");
        }

        for (i = 0; i < size; i++) {
            root = insert_newNode(&newData[i], root, &memoryMalloc);

            if (root != NULL) {
                printf("******************************\n");
                printf("Node inserted successfully\n");
                printf("Node data: %d\n", newData[i]);
                printf("******************************\n");
            }
            else {
                printf("Failed to insert new node\n");
            }
        }
    }
    else {
        printf("Failed to initialize root node\n");
    }

    //rootToLeftLeaf(root, &totalNode, &numLeftBlack);
    printf("Number of left branch black nodes: %d\n", numLeftBlack);
    printf("Total nodes: %d\n", totalNode);
    printf("\n");

    // Test deleting each node
    for (i = 0; i < size; i++) {
        delete_node(&root, &newData[i]);
        printf("Deleted node: %d\n", newData[i]);
    }

    printf("Size of newData: %d\n", size);
    for (i = 0; i < size; i++) {
        printf("newData content: %d\n", newData[i]);
    }

    free_node(root, &memoryMalloc);
    printf("Remaining allocated memory: %d\n", memoryMalloc);
    if (memoryMalloc == 0) {
        printf("Memory is empty\n");
    }
    else {
        printf("Persistent memory leaks\n");
    }

    return 0;
}
