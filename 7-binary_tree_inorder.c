#include "binary_trees.h"

/**
 * binary_tree_inorder - trverse the tree in inorder order and calls the func
 *                        for each node value
 * @tree: the root of the tree
 * @func: a function to be called for each value of the traversing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	(*func)(tree->n);
	binary_tree_inorder(tree->right, func);
}
