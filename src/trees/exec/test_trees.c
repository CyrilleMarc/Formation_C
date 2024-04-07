#include <stdio.h>
#include <string.h>

#include "trees/trees.h"
#include <common/common.h>


int main()
{
	int data = 100;
	Color color = BLACK;
	Node* left = NULL;
	Node* right = NULL;
	int parent = 0;
	

	logger_set_current_level(LOG_DEBUG);
	logger_log(LOG_DEBUG, __FUNCSIG__, "");

	Node *node = create_node(data);
	if (NULL != node)
	{
		printf("node->data = %d\n", node->data);
	}
	else
	{
		printf("Failed to create node");
	}
	
	insert_new_node(data, parent, left, right, color);

	return 0;

}