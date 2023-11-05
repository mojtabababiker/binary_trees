#include "binary_trees.h"

binary_tree_t *get_ancestor(const binary_tree_t *first,
			    const binary_tree_t *second);

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
	binary_tree_t *common_ancestor = NULL;

	if (first == NULL || second == NULL)
		return (NULL);

	common_ancestor = get_ancestor(first, second);
	if (common_ancestor)
		return (common_ancestor);
	common_ancestor = get_ancestor(first->parent, second);
	if (common_ancestor)
		return (common_ancestor);
	common_ancestor = get_ancestor(first, second->parent);
	if (common_ancestor)
		return (common_ancestor);
	return (NULL);
}


binary_tree_t *get_ancestor(const binary_tree_t *first,
			    const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (first->parent == second->parent)
		return (first->parent);

	if (first->parent == second)
		return (first->parent);

	if (second->parent == first)
		return (second->parent);

	return (binary_trees_ancestor(first->parent, second->parent));
}
