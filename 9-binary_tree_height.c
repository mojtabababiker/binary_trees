#include "binary_trees.h"

size_t get_height(const binary_tree_t *tree);

/**
 * binary_tree_height - calculate the height of a tree
 * @tree: the tree to calculate its height
 * Return: the height of the tree size_t
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (get_height(tree) - 1);
}


/**
 * get_height - recursivly calculate tge height of tree
 * @tree: the root node of the tree
 * Return: the height if the tree
 */
size_t get_height(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (tree == NULL)
		return (0);

	l_height += get_height(tree->left);
	r_height += get_height(tree->right);

	if (l_height > r_height)
		return (++l_height);

	return (++r_height);
}
