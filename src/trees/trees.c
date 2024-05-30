#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "trees/trees.h"
#include "common/common.h"


Node *init_node(int *data, int *memoryMalloc)
{
    Node *node = malloc(sizeof(Node));
    if (NULL == node)
    {
        logger_log(LOG_DEBUG, __FUNCSIG__, "Memory allocation failure");
        return NULL;
    }
    else
    {
        (*memoryMalloc)++;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;
        node->color = BLACK;
        return node;
    }
}

Node* insert_newNode(int* data, Node* root, int* memoryMalloc) {
    Node* current = root;
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        logger_log(LOG_DEBUG, __FUNCSIG__, "Memory allocation failure");
        return NULL;
    }
    (*memoryMalloc)++;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->color = RED;

    Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (*(newNode->data) < *(current->data)) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    newNode->parent = parent;
    if (parent == NULL) {
        root = newNode;
    }
    else if (*data < *(parent->data)) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

    insertFixUp(&root, newNode);

    return newNode;
}



 
void leftRotate(Node** root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        *root = y;
    }
    //si x est le fils gauche de x->parent assigner y comme fils gauche
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        // sinon l'assigner comme fils droit
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRotate(Node** root, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NULL) {
        *root = x;
    }
    else if (y == y->parent->right) {
        y->parent->right = x;
    }
    else {
        y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
}


void insertFixUp(Node** root, Node* k) {
    while (k->parent != NULL && k->parent->color == RED) {
        if (k->parent == k->parent->parent->left) {
            Node* u = k->parent->parent->right; // Oncle
            if (u != NULL && u->color == RED) {
                // Cas 1 : L'oncle est rouge
                u->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            }
            else {
                if (k == k->parent->right) {
                    // Cas 2 : k est le fils droit
                    k = k->parent;
                    leftRotate(root, k);
                }
                // Cas 3 : k est le fils gauche
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rightRotate(root, k->parent->parent);
            }
        }
        else {
            Node* u = k->parent->parent->left; // Oncle
            if (u != NULL && u->color == RED) {
                // Cas 1 : L'oncle est rouge
                u->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            }
            else {
                if (k == k->parent->left) {
                    // Cas 2 : k est le fils gauche
                    k = k->parent;
                    rightRotate(root, k);
                }
                // Cas 3 : k est le fils droit
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                leftRotate(root, k->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}



void free_node(Node* node, int* memoryMalloc) {
    if (node == NULL) {
        return;
    }
    free_node(node->left, memoryMalloc);
    free_node(node->right, memoryMalloc);
    free(node);
    (*memoryMalloc)--;
}


Color change_color(Node* newNode)
{
    if (newNode->parent->color == BLACK)
    {
        newNode->color = RED;
    }
    else
    {
        newNode->color = BLACK;
    }
}


int rootToLeftLeaf(Node* root, int* totalNode, int* numLeftBlack)
{
    if (NULL == root)
    {
        return;
    }

    Node* current = root->left;

    if (NULL == current)
    {
        return;
    }
        while (NULL != current)
        {
            if (BLACK == current->color)
            {
                (*numLeftBlack)++;
            }
            (*totalNode)++;
            printf("Node data %d & node color %d\n", *(current->data), current->color);
            current = current->left;
        }
 
    return 0;
}

int rootToRightLeaf(Node* root, int* totalNode, int* numRightBlack)
{
    if (NULL == root)
    {
        return;
    }

    Node* current = root->right;

    if (NULL == current)
    {
        return;
    }
    while (NULL != current)
    {
        if (BLACK == current->color)
        {
            (*numRightBlack)++;
        }
        (*totalNode)++;
        printf("Node data %d & node color %d\n", *(current->data), current->color);
        current = current->left;
    }

    return 0;
}

void delete_node(Node** root, int* data)
{
    Node* current = *root;
    Node* parent = NULL;

    if (NULL == current->left && NULL == current->right && *data == (*current->data))
    {
        free(current);
    }

    while (NULL != current && *data != *(current->data))
    {
        parent = current;
        if (*(current->data) < *data)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    if (NULL == current)
    {
        printf("Node not found\n");
        return;
    }
    
    if (NULL != current->left && NULL != current->right)
    {
        Node* successor = current->right;
        Node* successor_parent = current;

        while (NULL != successor->left)
        {
            successor_parent = successor;
            successor = successor->left;
        }

        current->data = successor->data;

        if (successor_parent != current)
            successor_parent->left = successor->right;
        else
            successor_parent->right = successor->right;

        free(successor);
    }
    else
    {
        Node* child = (NULL != current->left) ? current->left : current->right;

        if (NULL == parent)
        {
            *root = child;
        }
        else if (current == parent->left)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }
        if (NULL != child)
        {
            child->parent = parent;
        }
        free(current);
    }
}


