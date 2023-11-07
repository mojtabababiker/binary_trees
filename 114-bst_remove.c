#include "binary_trees.h"

bst_t *get_node(bst_t *tree, int value);
bst_t *delete_node(bst_t *node, bst_t *sub_node);
bst_t *get_sucs(bst_t *to_delete);
bst_t *delete_full_node(bst_t *node);

/**
 * bst_remove - delete the node that have the value `value` from the bst tree
 * @root: the root of the BST
 * @value: the value of the node to delete
 * Return: a pointer to the new root after deletion
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *to_delete = NULL, *parent = NULL, *temp = NULL;

	if (root == NULL)
		return (NULL);

	to_delete = get_node(root, value);

	if (to_delete == NULL)
		return (root);
	parent = to_delete->parent;
	if (!to_delete->left && !to_delete->right)
	{
		if (!parent)
		{
			free(to_delete);
			return (NULL);
		}
		to_delete->parent = NULL;
		if (to_delete == parent->left)
			parent->left = NULL;
		else
			parent->right = NULL;
		free(to_delete);
		return (root);
	}
	if (to_delete->left && !to_delete->right)
	{
		temp = delete_node(to_delete, to_delete->left);
		if (temp)
			return (temp);
		return (root);
	}
	if (to_delete->right && !to_delete->left)
	{
		temp = delete_node(to_delete, to_delete->right);
		if (temp)
			return (temp);
		return (root);
	}

	temp = delete_full_node(to_delete);
	if (temp)
		return (temp);
	return (root);
}

/**
 * get_node - search for the node that have the value `value` in the tree
 * @tree: a pointer to the root of the bst tree
 * @value: the value of the required node
 * Return: pointer to the node or NULL if it's not in the tree
 */
bst_t *get_node(bst_t *tree, int value)
{
	while (tree != NULL)
	{
		if (tree->n == value)
			return (tree);
		if (tree->n < value)
			tree = tree->right;
		else
			tree = tree->left;
	}
	return (NULL);
}

/**
 * delete_node - delete a node from a BST
 * @node: the node to be deleted
 * @sub_tree: determine the childe node direction
 * Return: pointer to the new root
 */
bst_t *delete_node(bst_t *node, bst_t *sub_tree)
{
	bst_t *parent = node->parent;

	if (parent && parent->left == node)
	{
		parent->left = sub_tree;
		sub_tree->parent = parent;
		free(node);
		return (NULL);
	}
	if (parent && parent->right == node)
	{
		parent->right = sub_tree;
		sub_tree->parent = parent;
		free(node);
		return (NULL);
	}

	sub_tree->parent = NULL;
	free(node);
	return (sub_tree);
}

/**
 * get_sucs - return the in-order successser of the tree
 * @tree: the node to finde its in-order successer
 * Return: pointer to the successer or NULL in failure
 */
bst_t *get_sucs(bst_t *tree)
{
	bst_t *node = NULL;

	if (tree->right == NULL)
		return (tree);
	tree = tree->right;
	node = tree;

	while (tree != NULL)
	{
		node = tree;
		tree = tree->left;
	}
	return (node);
}

/**
 * delete_full_node - delete node with both left and right sub-trees from BST
 * @node: pointer to the node to be deleted
 * Return: pointer to the replaced node, or NULL
 */
bst_t *delete_full_node(bst_t *node)
{
	bst_t *sucs = get_sucs(node);

	if (node->right != sucs)
	{
		sucs->parent->left = sucs->left;
		sucs->right = node->right;
	}

	sucs->parent = node->parent;
	sucs->left = node->left;

	if (node->left)
		node->left->parent = sucs;

	if (node->right && node->right != sucs)
		node->right->parent = sucs;

	if (!node->parent) /* this is the root node */
	{
		free(node);
		return (sucs);
	}

	if (node->parent->left == node)
		node->parent->left = sucs;
	else
		node->parent->right = sucs;

	free(node);
	return (NULL);
}
