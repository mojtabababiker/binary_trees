#include "binary_trees.h"

/**
 * binary_tree_delete - deletes all the node on the tree
 * @tree: the root of the tree
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
