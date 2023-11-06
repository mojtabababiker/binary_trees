#include "binary_trees.h"

int check_left(binary_tree_t *tree, int root_val);
int check_right(binary_tree_t *tree, int root_val);

/**
 * binary_tree_is_bst - check if the tree is binary search tree
 * @tree: a binary tree to check
 * Return: 1 if the tree is BST 0 other-wise
 * Description:
 *        Binary Search Tree is a binary in wich the left node if less than the
 *        current node, and the right node is greater than the current node, and
 *        all the sub-tree of the node are a binary search tree
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	binary_tree_t *l_node = NULL, *r_node = NULL;

	if (tree == NULL)
		return (0);
	l_node = tree->left;
	r_node = tree->right;

	return (check_left(l_node, tree->n) * check_right(r_node, tree->n));
}

/**
 * check_left - check the left sub-tree
 * @tree: the left sub-tree to check
 * @root_val: the value of the root
 * Return: 1 if the sub-tree is BST, 0 other-wise
 */
int check_left(binary_tree_t *tree, int root_val)
{
	binary_tree_t *l_node = NULL, *r_node = NULL;

	if (tree == NULL)
		return (1);

	l_node = tree->left;
	r_node = tree->right;
	/* if the tree is a leaf */
	if (!l_node && !r_node)
		return (1);
	/* if the left tree is null and the right tree value is > tree value */
	if (!l_node && r_node->n > tree->n)
	{
		if (r_node->n > root_val)
			return (0);
		return (1);
	}
	/* if the left tree value is < tree value and the right tree is null */
	if(l_node->n < tree->n && !r_node)
		return (1);
	/* if left val is > tree value or right value is < tree value */
	if (l_node->n > tree->n || r_node->n < tree->n)
		return (0);
	if (r_node->n > root_val)
		return (0);
	/* recursivly call for the function to check all the sub-trees */
	return (check_left(l_node, root_val) * check_left(r_node, root_val));
}

/**
 * check_right - check the right sub-tree
 * @tree: the left sub-tree to check
 * @root_val: the value of the root
 * Return: 1 if the sub-tree is BST, 0 other-wise
 */
int check_right(binary_tree_t *tree, int root_val)
{
	binary_tree_t *l_node = NULL, *r_node = NULL;

	if (tree == NULL)
		return (1);

	l_node = tree->left;
	r_node = tree->right;

	/* if the tree is a leaf */
	if (!l_node && !r_node)
		return (1);

	/* if the left tree is null and the right tree value is > tree value */
	if (!l_node && r_node->n > tree->n)
		return (1);

	/* if the left tree value is < tree value and the right tree is null */
	if(l_node->n < tree->n && !r_node)
	{
		if (l_node->n < root_val)
			return (0);
		return (1);
	}

	/* if left val is > tree value or right value is < tree value */
	if (l_node->n > tree->n || r_node->n < tree->n)
		return (0);
	if (l_node->n < root_val)
		return (0);
	/* recursivly call for the function to check all the sub-trees */
	return (check_right(l_node, root_val) * check_right(r_node, root_val));
}
