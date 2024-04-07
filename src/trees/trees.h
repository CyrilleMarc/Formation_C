#pragma once
#include <stdlib.h>

typedef enum { RED, BLACK } Color;
typedef struct Node Node;
struct Node
{
	int data;
	Color color;
	Node* left;
	Node* right;
	int parent;
};

Node* create_node(int data);
Node* insert_new_node(int data, int parent, Node* left, Node* right, Color color);