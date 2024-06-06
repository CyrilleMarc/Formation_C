#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "RedAndBlackTrees/RedAndBlackTrees.h"
#include "common/common.h"

int main() {
    int tab[] = { 100, 50, 80, 150, 30, 110 };
    int size = sizeof(tab) / sizeof(int);
    Node* root = NULL;

    for (int i = 0; i < size; i++) {
        root = insert_newNode(root, tab[i]);
    }

    Node* current = root;
    while (current != NULL) {
        printf("Node key => %d\n", current->key);
        if (current->color == BLACK) {
            printf("Node color => BLACK\n");
        }
        else {
            printf("Node color => RED\n");
        }
        current = current->left;
        printf("\n");
    }

    return 0;
}
