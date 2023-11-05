#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate the tree to the right by one node
 * @tree: the root of the tree
 * Return: pointer to the new root
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root = NULL, *temp = NULL;

	if (tree == NULL)
		return (NULL);

	if (tree->left == NULL)
		return (tree);

	root = tree->left;
	tree->parent = root;
	root->parent = NULL;

	if (!root->right)
	{
		root->right = tree;
		tree->left = NULL;
	}
	else
	{
		temp = root->right;
		root->right = tree;
		tree->left = temp;
		temp->parent = tree;
	}
	return (root);
}
