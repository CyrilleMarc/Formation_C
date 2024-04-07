#include <stdio.h>
#include <string.h>

#include "trees/trees.h"
#include "common/common.h"



Node* create_node(int data)
{
	Node* node = NULL;
	node = malloc(sizeof(Node));
	if (NULL == node)
	{
		logger_log(LOG_DEBUG, __FUNCSIG__, "Memory allocation failure");
		return NULL;
	}
	else
	{
		node->color = BLACK;
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		node->parent = 0;

		return node;
	}
}

Node* insert_new_node(int data, int parent, Node* left, Node* right, Color color)
{
	Node* newNode = create_node(data);
	
}
