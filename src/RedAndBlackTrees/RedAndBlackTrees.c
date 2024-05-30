#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "trees/trees.h"
#include "common/common.h"


Node* init_node(Node* root, int data)
{
	Node* root = malloc(sizeof(Node));
	if (NULL == root)
	{
		printf("Memory allocation failure");
		return NULL;
	}
	else
	{

	}
}