#include "binary_trees.h"

/**
 * binary_trees_ancestor - find the lowest common ancestor of two nodes
 * @first: the first node from the tree, to check
 * @second: the second node from the tree
 * Return: the lowest common ancestor between the second and first or NULL
 *         if there an error or there are no common ancestor between them.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first->parent == second->parent)
		return (first->parent);

	if (first->parent == second)
		return (first->parent);
	if (second->parent == first)
		return (second->parent);

	c_a =  binary_trees_ancestor(first->parent, second->parent);

	if (c_a)
		return (c_a);
	if (first->parent)
		return ((binary_tree_t *)second);
	if (second->parent)
		return ((binary_tree_t *)first);
	return (NULL);
}
