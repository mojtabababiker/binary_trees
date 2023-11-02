#include "binary_trees.h"

size_t get_height(const binary_tree_t *tree);

/**
 * binary_tree_is_full - check if the tree is a full balanced tree
 * @tree: the root node of the tree
 * Return: 1 if the tree is full 0 other-wise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int l_height = 0 , r_height = 0;
	int balanced = 0, l_balanced = 0, r_balanced = 0;

	if (tree == NULL)
		return (0);

	l_height = get_height(tree->left);
	r_height = get_height(tree->right);

	balanced = l_height - r_height;
	l_balanced = binary_tree_is_full(tree->left);
	r_balanced = binary_tree_is_full(tree->right);

	if (!balanced && l_balanced && r_balanced)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
		if (!balanced)
			return (1);
	return (0);
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
