#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "trees/trees.h"
#include "common/common.h"

// Initialisation du nœud racine
Node* init_node(int* data, int* memoryMalloc) {
    Node* node = malloc(sizeof(Node));
    if (NULL == node) {
        logger_log(LOG_DEBUG, __FUNCSIG__, "Memory allocation failure");
        return NULL;
    }
    else {
        (*memoryMalloc)++;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;
        node->color = BLACK;
        return node;
    }
}

// Fonction pour insérer un nouveau nœud
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

    return root;
}

// Rotation gauche
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
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// Rotation droite
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

// Fonction pour équilibrer l'arbre après l'insertion
void insertFixUp(Node** root, Node* k) {
    while (k->parent != NULL && k->parent->color == RED) {
        if (k->parent->parent != NULL) {
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
                    if (k->parent->parent != NULL) {
                        k->parent->parent->color = RED;
                        rightRotate(root, k->parent->parent);
                    }
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
                    if (k->parent->parent != NULL) {
                        k->parent->parent->color = RED;
                        leftRotate(root, k->parent->parent);
                    }
                }
            }
        }
        else {
            break;
        }
    }
    (*root)->color = BLACK;
}

// Fonction pour équilibrer l'arbre après la suppression
void deleteFixUp(Node** root, Node* x) {
    while (x != *root && (x == NULL || x->color == BLACK)) {
        if (NULL != x)
        {
            if (x == x->parent->left) {
                Node* w = x->parent->right;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(root, x->parent);
                    w = x->parent->right;
                }
                if ((w->left == NULL || w->left->color == BLACK) && (w->right == NULL || w->right->color == BLACK)) {
                    w->color = RED;
                    x = x->parent;
                }
        }
            else {
                if (w->right == NULL || w->right->color == BLACK) {
                    if (w->left != NULL) w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(root, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->right != NULL) w->right->color = BLACK;
                leftRotate(root, x->parent);
                x = *root;
            }
        }
        else {
            Node* w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(root, x->parent);
                w = x->parent->left;
            }
            if ((w->right == NULL || w->right->color == BLACK) && (w->left == NULL || w->left->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            }
            else {
                if (w->left == NULL || w->left->color == BLACK) {
                    if (w->right != NULL) w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->left != NULL) w->left->color = BLACK;
                rightRotate(root, x->parent);
                x = *root;
            }
        }
    }
    if (x != NULL) x->color = BLACK;
}


// Fonction pour supprimer un nœud
void delete_node(Node** root, int* data) {
    Node* z = *root;
    Node* x;
    Node* y;

    while (z != NULL && *(z->data) != *data) {
        if (*data < *(z->data)) {
            z = z->left;
        }
        else {
            z = z->right;
        }
    }

    if (z == NULL) {
        printf("Node not found\n");
        return;
    }

    y = z;
    Color yOriginalColor = y->color;

    if (z->left == NULL) {
        x = z->right;
        if (x != NULL) x->parent = z->parent;
        if (z->parent == NULL) {
            *root = x;
        }
        else if (z == z->parent->left) {
            z->parent->left = x;
        }
        else {
            z->parent->right = x;
        }
        free(z);
    }
    else if (z->right == NULL) {
        x = z->left;
        if (x != NULL) x->parent = z->parent;
        if (z->parent == NULL) {
            *root = x;
        }
        else if (z == z->parent->left) {
            z->parent->left = x;
        }
        else {
            z->parent->right = x;
        }
        free(z);
    }
    else {
        y = z->right;
        while (y->left != NULL) {
            y = y->left;
        }
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent != NULL && y->parent == z) {
            if (x != NULL) x->parent = y;
        }
        else {
            if (x != NULL) x->parent = y->parent;
            if (y->parent != NULL) y->parent->left = x;
            y->right = z->right;
            if (y->right != NULL) y->right->parent = y;
        }
        if (z->parent == NULL) {
            *root = y;
        }
        else if (z == z->parent->left) {
            z->parent->left = y;
        }
        else {
            z->parent->right = y;
        }
        y->parent = z->parent;
        y->color = z->color;
        y->left = z->left;
        if (y->left != NULL) y->left->parent = y;
        free(z);
    }

    if (yOriginalColor == BLACK) {
        deleteFixUp(root, x);
    }
}


// Fonction pour libérer la mémoire d'un nœud
void free_node(Node* node, int* memoryMalloc) {
    if (node == NULL) {
        return;
    }
    free_node(node->left, memoryMalloc);
    free_node(node->right, memoryMalloc);
    free(node);
    (*memoryMalloc)--;
}

// Autres fonctions (rootToLeftLeaf, rootToRightLeaf) ...

