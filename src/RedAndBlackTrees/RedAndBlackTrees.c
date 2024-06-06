#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "RedAndBlackTrees.h"
#include "common/common.h"

Node* insert_newNode(Node* root, int key) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        logger_log(LOG_DEBUG, __FUNCSIG__, "Memory allocation failure");
        return root;
    }

    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->color = RED;

    if (root == NULL) {
        newNode->color = BLACK; 
        return newNode;
    }

    Node* current = root;
    Node* parent = NULL;


    while (current != NULL) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    newNode->parent = parent;
    if (key < parent->key) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

    return root;
}

void leftRotation(Node** root, Node* x)
{

}

void rightRotation(Node** root, Node* y)
{

}

void fixViolation(Node* root, Node* z)
{

}