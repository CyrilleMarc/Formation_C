#include <stdio.h>
#include <stdlib.h>

#include <common/common.h>
#include <arbre_binaire/arbre_binaire.h>

Tree* new_Binary_Tree(int number)
{
	Tree* newTree = malloc(sizeof(Tree));
	if(NULL == newTree)
	{
		logger_log(LOG_DEBUG, __FUNCSIG__, "memory allocation failure");
		exit(0);
	}

	newTree->number = number;
	newTree->tleft = NULL;
	newTree->tright = NULL;
	newTree->parent = NULL;

	printf("c=reation arbre -> %d\n", newTree->number);
	logger_log(LOG_INFO, __FUNCSIG__, "Tree created successfully");

	return newTree;
}

int freeTree(Tree* tree)
{
	if (NULL == tree)
	{
		return;
	}
	freeTree(tree->tleft);
	freeTree(tree->tright);
	free(tree);
	logger_log(LOG_INFO, __FUNCSIG__, "Tree cleaned successfully");
	return 0;
}

Tree* joinTree(Tree* left, Tree* right, int node)
{
	Tree* tree = new_Binary_Tree(node);

	tree->tleft = left;
	tree->tright = right;

	if (NULL != left)
	{
		left->parent = tree;
	}
	if (NULL != right)
	{
		right->parent = tree;
	}
	return tree;
}

//prefixe -> tout les left en premier
int display_binary_tree(Tree* tree)
{
	if (NULL == tree)
	{
		logger_log(LOG_DEBUG, __FUNCSIG__, "Tree is empty");
		return;
	}

	if (NULL != tree->parent)
	{
		printf("(%d)-> (%d)\n", tree->parent->number, tree->number);
	}
	else
	{
		printf("(%d)\n", tree->number);
	}
	if (NULL != tree->tleft)
	{
		display_binary_tree(tree->tleft);
	}
	if (NULL != tree->tright)
	{
		display_binary_tree(tree->tright);
	}
	return tree;
}

int tree_count(Tree *tree)
{
	if (NULL == tree)
	{
		logger_log(LOG_DEBUG, __FUNCSIG__, "Tree is empty");
		return 0;
	}
	else 
	{
		return 1 + tree_count(tree->tleft) + tree_count(tree->tright);
	
	}
}