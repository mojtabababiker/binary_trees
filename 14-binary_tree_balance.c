#include "binary_trees.h"

size_t get_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - calculate the balance factor of the tree
 * @tree: the root node of the tree
 * Return: the balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int l_height = 0 , r_height = 0;

	if (tree == NULL)
		return (0);

	l_height = get_height(tree->left);
	r_height = get_height(tree->right);

	return (l_height - r_height);
}

/**
 * get_height - recursivly calculate the height of tree
 * @tree: the root node of the tree
 * Return: the height of the tree
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
