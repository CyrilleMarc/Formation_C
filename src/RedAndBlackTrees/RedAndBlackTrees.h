#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef enum { BLACK, RED } Color;

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    Color color;
} Node;

Node* insert_newNode(Node* root, int key);
