#include "binary_trees.h"

/**
 * array_to_bst - generate a Binary Search tree from a given array
 * @array: the array of integer that represent the bst values
 * @size: size of the array
 * Return: pointer to the root of the bst
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root = NULL;

	if (array == NULL || size == 0)
		return (NULL);
	root = bst_insert(&root, array[i]);
	for (i = 1 ; i < size ; i++)
	{
		bst_insert(&root, array[i]);
	}
	return (root);
}
