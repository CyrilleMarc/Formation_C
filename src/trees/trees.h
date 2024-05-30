#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;
typedef struct Node Node;

struct Node {
    int* data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;
};

Node* init_node(int* data, int* memoryMalloc);
Node* insert_newNode(int* data, Node* root, int* memoryMalloc);
void free_node(Node* node, int* memoryMalloc);
void leftRotate(Node** root, Node* x);
void rightRotate(Node** root, Node* y);
void insertFixUp(Node** root, Node* k);
int rootToLeftLeaf(Node* root, int* totalNode, int* numLeftBlack);
int rootToRightLeaf(Node* root, int* totalNode, int* numRightBlack);
void delete_node(Node** root, int* numOfNode);
