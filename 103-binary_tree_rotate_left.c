#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate the tree to the left by one node
 * @tree: the root of the tree
 * Return: pointer to the new root
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root = NULL, *temp = NULL;

	if (tree == NULL)
		return (NULL);

	if (tree->right == NULL)
		return (tree);

	root = tree->right;
	tree->parent = root;
	root->parent = NULL;

	if (!root->left)
	{
		root->left = tree;
		tree->right = NULL;
	}
	else
	{
		temp = root->left;
		root->left = tree;
		tree->right = temp;
		temp->parent = tree;
	}
	return (root);
}
