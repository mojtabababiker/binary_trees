#include "binary_trees.h"

/**
 * bst_insert - insert a value in a Binary Search Tree
 * @tree: a pointer to pointer of the root node of the tree
 * @value: the  value to be inserted
 * Return: pointer to the newly created value
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new = NULL, *temp = NULL, *prev = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = (bst_t *)binary_tree_node(NULL, value);
		return (*tree);
	}

	temp = *tree;
	while (temp != NULL)
	{
		prev = temp;
		if (value == temp->n)
			return (NULL);

		if (value < temp->n)
			temp = temp->left;
		else
			temp = temp->right;
	}
	new = (bst_t *)create(value);
	new->parent = prev;

	if (prev->n > value)
		prev->left = new;
	else
		prev->right = new;

	return (new);
}
