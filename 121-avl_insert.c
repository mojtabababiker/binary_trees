#include "binary_trees.h"

avl_t *avl_balance(avl_t *new);

/**
 * avl-insert - insert a new node into the AVL tree
 * @tree: pointer to the root pointer of the AVL tree
 * @value: the value of the new node
 * Return: a pointer to the newly created node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL, *parent = NULL, *temp = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = (avl_t *)binary_tree_node(NULL, value);
		return (*tree);
	}

	temp = *tree;
	while (temp)
	{
		parent = temp;
		if (temp->n == value)
			return (NULL);
		if (temp->n > value)
			temp = temp->left;
		else
			temp = temp->right;
	}
	new = (avl_t *)create(value);
	if (!new)
		return (NULL);
	new->parent = parent;
	if (parent->n > value)
		parent->left = new;
	else
		parent->right = new;

	temp = avl_balance(new);
	if (temp && temp->parent == NULL) /* the new root */
		*tree = temp;
	return (new);
}

/**
 * avl_balance - balance an AVL tree
 * @new: a newly inserted nood that may effict the tree balance
 * Return: pointer to the new root of the balanced tree
 */
avl_t *avl_balance(avl_t *new)
{
	int balance_factor = 0, value = 0;
	avl_t *temp = NULL, *parent = NULL;

	parent = new->parent;
	value = new->n;
	while (parent != NULL)
	{
		balance_factor = binary_tree_balance(parent);
		if (balance_factor > 1)
		{
			if (value > parent->left->n)
				binary_tree_rotate_left(parent->left);

			temp = binary_tree_rotate_right(parent);
			parent = new;
		}
		else if (balance_factor < -1)
		{
			if (value < parent->right->n)
				binary_tree_rotate_right(parent->left);

			temp = binary_tree_rotate_left(parent);
			parent = new;
		}
		parent = parent->parent;

	}
	return (temp);
}
