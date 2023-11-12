#include "binary_trees.h"

avl_t *get_successor(avl_t *node);
avl_t *swap_sucs(avl_t *sucs, avl_t *node);
avl_t *_avl_balance(avl_t *new);

/**
 * avl_remove - removes a node from an AVl tree and balances it if necessary
 * @root: pointer to root of the AVL tree
 * @value: the value of the node to remove
 * Return: a pointer to the new root of the AVL tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp = root, *sucs = NULL, *parent = NULL;

	if (root == NULL)
		return (root);

	while (temp->n != value)
	{
		if (!temp)
			return (temp);

		if (temp->n > value)
			temp = temp->left;
		else
			temp = temp->right;
	}
	sucs = get_successor(temp);
	if (sucs == temp && !temp->left) /* leafe node or a single node tree */
	{
		if (temp->parent && temp == temp->parent->left)
			temp->parent->left = NULL;
		else if (temp->parent)
			temp->parent->right = NULL;
		parent = temp->parent;
		free(temp);
		temp = _avl_balance(parent);
		if (temp && temp->parent == NULL) /* new root */
			return (temp);
		return (root);
	}
	parent = swap_sucs(sucs, temp); /*swap the node with its successor */
	free(temp);
	temp = _avl_balance(parent);
	if (temp && temp->parent == NULL) /* new root */
		return (temp);
	if (sucs && sucs->parent == NULL)
		return (sucs);
	return (root);
}

/**
 * get_successor - search for the in-order successor of the node `node`
 * @node: pointer the node to get ins successor
 * Return: pointer to the node successor or NULL in failure
 */
avl_t *get_successor(avl_t *node)
{
	avl_t *sucs = NULL;

	if (!node || !node->right)
		return (node);

	sucs = node->right;

	while (sucs->left)
	{
		sucs = sucs->left;
	}
	return (sucs);
}
/**
 * swap_sucs - swap the node to be delete with its seccussor
 * @sucs: pointer to the node seccussor
 * @node: pointer to the node the will be deleted
 * Return: pointer to the sucs after swap
 */
avl_t *swap_sucs(avl_t *sucs, avl_t *node)
{
	if (sucs == node)
	{
		if (node->parent)
		{
			if (node->parent->left == node)
			{
				node->parent->left = node->left;
				if (node->left)
					node->left->parent = node->parent;
			}
			else
			{
				node->parent->right = node->left;
				if (node->left)
					node->left->parent = node->parent;
			}
			return (node->parent);
		}
		node->left->parent = NULL;
		return (node->left);
	}
	if (sucs != node->right)
	{
		sucs->parent->left = sucs->right;
		if (sucs->right)
			sucs->right->parent = sucs->parent;
		sucs->right = node->right;
		if (node->right)
			node->right->parent = sucs;
	}
	sucs->parent = node->parent;
	sucs->left = node->left;
	if (node->left)
		node->left->parent = sucs;
	if (node->parent && node->parent->left == node)
		node->parent->left = sucs;
	else if (node->parent)
		node->parent->right = sucs;
	return (sucs);
}

/**
 * _avl_balance - balance an AVL tree
 * @node: a newly inserted nood that may effict the tree balance
 * Return: pointer to the new root of the balanced tree
 */
avl_t *_avl_balance(avl_t *node)
{
	int balance_factor = 0, value = 0;
	avl_t *temp = NULL, *parent = node;

	if (parent)
		value = parent->n;

	while (parent != NULL)
	{
		balance_factor = binary_tree_balance(parent);
		if (balance_factor < -1)
		{
			if (value < parent->right->n)
				binary_tree_rotate_right(parent->left);

			temp = binary_tree_rotate_left(parent);
		}

		if (balance_factor > 1)
		{
			if (value < parent->left->n)
				binary_tree_rotate_left(parent->left);

			temp = binary_tree_rotate_right(parent);
		}
		parent = parent->parent;
	}

	return (temp);
}
