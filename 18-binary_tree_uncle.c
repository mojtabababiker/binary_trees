#include "binary_trees.h"

/**
 * binary_tree_sibling - find the uncle of the node
 * @node: the node to find it's uncle
 * Return: a pointer to node uncle or NULL if the node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *node_parent = NULL, *node_grand = NULL;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	node_parent = node->parent;
	node_grand = node_parent->parent;
	if (node_grand == NULL)
		return (NULL);

	if (node_grand->left == node_parent)
		return (node_grand->right);
	else if (node_grand->right == node_parent)
		return (node_grand->left);
	return (NULL);
}
