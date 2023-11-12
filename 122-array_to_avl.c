#include "binary_trees.h"

/**
 * array_to_avl - convert an array into AVL binary tree
 * @array: pointer to the first element of the array
 * @size: the size of the array
 * Return: a pointer to the root of the AVL tree
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i = 0;

	if (array == NULL)
		return (NULL);

	root = (avl_t *)binary_tree_node(NULL, array[0]);

	if (root == NULL)
		return (NULL);

	for (i = 1 ; i < size ; i++)
	{
		avl_insert(&root, array[i]);
	}
	return (root);
}
