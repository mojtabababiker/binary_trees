#include "binary_trees.h"

/**
 * binary_tree_node - create a new node as a child of the parent node
 * @parent: a binary_tree_node as the parent for the new node
 * @n: the valie of the new node
 * Return: pointer to the new node or NULL in failuer
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int n)
{
	binary_tree_t *new_node = create(n);

	if (new_node == NULL)
		return (NULL);

	new_node->parent = parent;

	if (parent == NULL)
		return (new_node); /* the root node */

	if (parent->left == NULL) /* Empty slot at the left */
		parent->left = new_node;

	else
		parent->right = new_node;

	return (new_node);
}

/**
 * create - allocate and initializes a new binary_tree_t pointer
 * @n: the n of the new node
 * Return: a pointer to the created node or NULL in failuer
 */
binary_tree_t *create(int n)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (new == NULL)
		return (NULL);
	new->n = n;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
