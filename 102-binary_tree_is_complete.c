#include "binary_trees.h"

/**
 * binary_tree_is_complete - check if the tree is complete tree
 * @tree: the root node of tree
 * Return: 1 if the tree is complete 0 otherwise
 * Description:
 *       A complete binary tree is complete if all the nodes are filled
 *       with 2 nodes except maybe the last level where all the leaves nodes
 *       most be as left as possiable
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int is_complete;

	if (tree == NULL)
		return (0);

	if ((tree->left && tree->right) ||
	    (tree->left && !tree->right) ||
	    (!tree->left && !tree->right))
		return (1);

	is_complete = binary_tree_is_complete(tree->left) *
		binary_tree_is_complete(tree->right);
	return (is_complete);
}
