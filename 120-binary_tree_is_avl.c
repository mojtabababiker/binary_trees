#include "binary_trees.h"

int check_right(binary_tree_t *tree, int root_val);
int check_left(binary_tree_t *tree, int root_val);
int get_height(binary_tree_t *tree);

/**
 * binary_tree_is_avl - check if the tree is an AVL binary tree
 * @tree: pointer to the tree to be checked
 * Retrun: 1 if the tree is AVL, 0 other-wise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int is_bstree = 0, is_balanced = 0;

	if (tree == NULL)
		return (0);

	is_bstree = check_left(tree->left, tree->n) * check_right(tree->right,
								  tree->n);
	if (!is_bstree)
		return (0);
	is_balanced = get_height(tree->left) - get_height(tree->right);

	if (is_balanced < -1 || is_balanced > 1)
		return (0);
	return (1);
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
	if (l_node->n < tree->n && !r_node)
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
	if (l_node->n < tree->n && !r_node)
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

/**
 * get_height - calcualte the height of a tree
 * @tree: a binary tree to calculate its height
 * Return: the heihgt of the tree
 */
int get_height(binary_tree_t *tree)
{
	int l_height = 0, r_height = 0;

	if (tree == NULL)
		return (0);
	l_height += get_height(tree->left);
	r_height += get_height(tree->right);

	if (l_height > r_height)
		return (++l_height);
	return (++r_height);
}
