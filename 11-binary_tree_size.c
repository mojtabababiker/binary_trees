#include "binary_trees.h"

/**
 * binary_tree_size - calculate the number of nodes in the tree tree
 * @tree: root of the tree
 * Return: the size of the tree (no. nodes)
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t l_size = 1, r_size = 1;

	if (tree == NULL)
		return (0);

	l_size += binary_tree_size(tree->left);
	r_size += binary_tree_size(tree->right);

	return ((l_size + r_size) - 1);
}
