#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate the tree to the right by one node
 * @tree: the root of the tree
 * Return: pointer to the new root
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *l_node = NULL, *temp = NULL;

	if (tree == NULL)
		return (NULL);

	if (tree->left == NULL)
		return (tree);

	l_node = tree->left;
	l_node->parent = tree->parent;
	tree->parent = l_node;

	if (l_node->parent)
	{
		if (l_node->parent->n > l_node->n)
			l_node->parent->left = l_node;
		else
			l_node->parent->right = l_node;
	}
	if (!l_node->right)
	{
		l_node->right = tree;
		tree->left = NULL;
	}
	else
	{
		temp = l_node->right;
		l_node->right = tree;
		tree->left = temp;
		temp->parent = tree;
	}
	return (l_node);
}
