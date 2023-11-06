#include "binary_trees.h"

/**
 * bst_search - search for the `value` in the bst `tree`
 * @tree: the Binary Search Tree to search on
 * @value: the required value
 * Return: pointer to node that contianing the value `value`
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	while (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n < value)
			tree = tree->right;
		else
			tree = tree->left;
	}
	return (NULL);
}
