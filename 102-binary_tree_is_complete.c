#include "binary_trees.h"

int get_height(const binary_tree_t *tree);
int is_complete(const binary_tree_t *tree, int height);

/**
 * binary_tree_is_complete - check if the tree is complete tree
 * @tree: the root node of tree
 * Return: 1 if the tree is complete 0 otherwise
 * Description:
 *       A complete binary tree is complete if all the nodes are filled
 *       with 2 nodes except maybe the last level where all the leaves nodes
 *       most be as left as possiable
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int complete_tree;
	int height;

	if (tree == NULL)
		return (0);
	height = get_height(tree) - 1;

	printf("\t[[[[[ hieght = %d]]]]]\n", height);
	complete_tree = is_complete(tree, height - 1);
	return (complete_tree);
}

/**
 * get_height - recursivly calculate tge height of tree
 * @tree: the root node of the tree
 * Return: the height if the tree
 */
int get_height(const binary_tree_t *tree)
{
	int l_height = 0, r_height = 0;

	if (tree == NULL)
		return (0);

	l_height += get_height(tree->left);
	r_height += get_height(tree->right);

	if (l_height > r_height)
		return (++l_height);

	return (++r_height);
}

/**
 * is_complete - check the tree if it is a complete tree or not
 * @tree: the tree to check
 * @height: the height of the tree
 * Return: 1 if the tree is complete 0 other-wise
 */
int is_complete(const binary_tree_t *tree, int height)
{
	if (tree == NULL)
		return (0);

	if (height <= 0)
	{
		if (!tree->left && tree->right)
			return (0);
		return (1);
	}
	else if (!tree->left && tree->right)
		return (0);
	else if (tree->left && !tree->right)
		return (0);
	else if (!tree->left && !tree->right)
		return (0);
	return (is_complete(tree->left, height - 1) *
		is_complete(tree->right, height - 1));
}
