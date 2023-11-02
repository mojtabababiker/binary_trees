#include "binary_trees.h"

/**
 * binary_tree_is_full - check if the tree is a full balanced tree
 * @tree: the root node of the tree
 * Return: 1 if the tree is full 0 other-wise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int l_balanced = 0, r_balanced = 0;

	if (tree == NULL)
		return (0);

	l_balanced = binary_tree_is_full(tree->left);
	r_balanced = binary_tree_is_full(tree->right);

	if (l_balanced && r_balanced)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (0);
}
