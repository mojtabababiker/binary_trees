#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a new node at the left side of the parent
 * @parent: the node to insert the new node on it is left sub tree
 * @value: the value of the new node
 * Return: a pointer to the new inserted node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = create(value);
	if (new_node == NULL)
		return (NULL);

	new_node->parent = parent;
	new_node->left = parent->left;

	if (parent->left)
	{
		parent->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}
