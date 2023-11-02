#include "binary_trees.h"

/**
 * binary_tree_sibling - find the sipling of the node
 * @node: the node to find it's sipling
 * Return: a pointer to node sipling or NULL if the node has no sipling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *node_parent = NULL;

	if (node == NULL || node->parent == NULL)
		return NULL;

	node_parent = node->parent;

	if (node_parent->left == node)
		return (node_parent->right);
	else if (node_parent->right == node)
		return (node_parent->left);
	return (NULL);
}
