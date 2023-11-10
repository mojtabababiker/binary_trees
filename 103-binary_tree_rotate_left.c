#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate the tree to the left by one node
 * @tree: the root of the tree
 * Return: pointer to the new root
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *r_node = NULL, *temp = NULL;

	if (tree == NULL)
		return (NULL);

	if (tree->right == NULL)
		return (tree);

	r_node = tree->right;
	r_node->parent = tree->parent;
	tree->parent = r_node;

	if (r_node->parent)
	{
		if (r_node->parent->n > r_node->n)
			r_node->parent->left = r_node;
		else
			r_node->parent->right = r_node;
	}
	if (!r_node->left)
	{
		r_node->left = tree;
		tree->right = NULL;
	}
	else
	{
		temp = r_node->left;
		r_node->left = tree;
		tree->right = temp;
		temp->parent = tree;
	}
	return (r_node);
}
