#include "binary_trees.h"

/**
 * binary_tree_is_root - check if node is a root node
 * @node: the node to be checked
 * Return: 1 if it is a root 0 other wise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	return (1);
}
