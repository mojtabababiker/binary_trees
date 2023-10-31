#include "binary_trees.h"

/**
 * binary_tree_postorder - trverse the tree in postorder order and
 *                         calls the func for each node value
 * @tree: the root of the tree
 * @func: a function to be called for each value of the traversing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	(*func)(tree->n);
}
