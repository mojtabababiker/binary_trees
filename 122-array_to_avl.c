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

	if (array == NULL)
		return (NULL);

	root = create(*array++);

	if (root == NULL)
		return (NULL);

	while (size > 0)
	{
		printf(">>> %lu\n", size);
		avl_insert(&root, *array);
		printf("\ninserted: %d\n", *array++);
		size--;
	}
	return (root);
}
