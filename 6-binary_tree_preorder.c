#include "binary_trees.h"

/**
 * binary_tree_preorder - trverse the tree in preorder order and calls the func
 *                        for each node value
 * @tree: the root of the tree
 * @func: a function to be called for each value of the traversing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	(*func)(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
