#include "binary_trees.h"

size_t get_depth(const binary_tree_t *tree);

/**
 * binary_tree_depth - calculate the depth of the tree
 * @tree: the tree to calculate its depth
 * Return: the depth of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (get_depth(tree));
}

/**
 * get_depth - recursivly calculate tge depth of tree
 * @tree: the root node of the tree
 * Return: the depth if the tree
 */
size_t get_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree->parent == NULL)
		return (0);

	depth += get_depth(tree->parent);

	return (++depth);
}
