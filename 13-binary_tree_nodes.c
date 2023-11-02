#include "binary_trees.h"

/**
 * binary_tree_nodes - calculate the n.o nodes in a tree not including leaves
 * @tree: root of the tree
 * Return: the number of nodes not included leaves
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL || tree->right != NULL)
		++nodes;
	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);

	return (nodes);
}
