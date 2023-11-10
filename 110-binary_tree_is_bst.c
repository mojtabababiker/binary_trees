#include "binary_trees.h"

int is_binary_search_tree(const binary_tree_t *tree);
binary_tree_t *get_min(binary_tree_t *tree);
binary_tree_t *get_max(binary_tree_t *tree);
/**
 * binary_tree_is_bst - check if the binary tree given is Binary Search Tree
 * @tree: pointer to the root node of the tree
 * Return: 1 if the tree is BST, 0 other-wise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_binary_search_tree(tree));
}

/**
 * is_binary_search_tree - check if the binary tree given is Binary Search Tree
 * @tree: pointer to the root node of the tree
 * Return: 1 if the tree is BST, 0 other-wise
 */
int is_binary_search_tree(const binary_tree_t *tree)
{
	int is_bst = 0;
	binary_tree_t *max_left = NULL, *min_right = NULL;

	if (tree == NULL)
		return (1);

	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
		max_left = get_max(tree->left);
	if (tree->right)
		min_right = get_min(tree->right);

	is_bst = is_binary_search_tree(tree->left) *
		is_binary_search_tree(tree->right);

	/* the root value of the subtree should be less than all it's */
	/* + right siplings values, and greater than all it's left */
	/* + siplings values, if NOT then return zero */
	if (max_left && tree->n < max_left->n)
			return (0);
	if (min_right && tree->n > min_right->n)
			return (0);

	return (is_bst);
}

/**
 * get_min - find the minimum value in the sub-tree
 * @tree: the root of the sub-tree to check
 * Return: pointer to the node witth the minimum value, or NULL in failure
 */
binary_tree_t *get_min(binary_tree_t *tree)
{
	binary_tree_t *min_left = NULL, *min_right = NULL, *min = NULL;

	if (tree == NULL)
		return (NULL);

	if (!tree->left && !tree->right)
		return (tree);

	min = tree;
	min_left = get_min(tree->left);
	min_right = get_min(tree->right);

	if (min_left && min_left->n < min->n)
		min = min_left;
	if (min_right && min_right->n < min->n)
		min = min_right;
	return (min);
}

/**
 * get_max - find the maximum value in the sub-tree
 * @tree: the root of the sub-tree to check
 * Return: pointer to the node witth the maximum value, or NULL in failure
 */
binary_tree_t *get_max(binary_tree_t *tree)
{
	binary_tree_t *max_left = NULL, *max_right = NULL, *max = NULL;

	if (tree == NULL)
		return (NULL);

	if (!tree->left && !tree->right)
		return (tree);

	max = tree;
	max_left = get_max(tree->left);
	max_right = get_max(tree->right);

	if (max_left && max_left->n > max->n)
		max = max_left;
	if (max_right && max_right->n > max->n)
		max = max_right;
	return (max);
}
