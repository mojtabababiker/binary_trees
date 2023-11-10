#include "binary_trees.h"

/**
 * avl-insert - insert a new node into the AVL tree
 * @tree: pointer to the root pointer of the AVL tree
 * @value: the value of the new node
 * Return: a pointer to the newly created node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL, *parent = NULL, *temp = NULL;
	int balance_factor = 0;

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

	while (parent)
	{
		balance_factor = binary_tree_balance(parent);
		if (balance_factor > 1)
		{
			if (new->n > new->parent->n)
				binary_tree_rotate_left(new->parent);
			temp = binary_tree_rotate_right(parent);
			break;
		}
		else if (balance_factor < -1)
		{
			if (new->n < new->parent->n)
				binary_tree_rotate_right(new->parent);
			temp = binary_tree_rotate_left(parent);
			break;
		}
		parent = parent->parent;
	}

	return (new);
}
