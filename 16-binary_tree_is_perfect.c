# include "binary_trees.h"

size_t get_height(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - check if the tree is a perfect tree
 * @tree: the root of the tree
 * Return: 1 if the tree is perfect 0 other-wise
 * Description:
 *      A tree is perfect if:
 *          1] all its nodes are in the same level
 *          2] each node has 2 childeren, except the leaves
 *          3] each sub-tree of the tree is a perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l_height = 0, r_height = 0;
	int l_tree = 0, r_tree = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	l_height = get_height(tree->left);
	r_height = get_height(tree->right);

	l_tree = binary_tree_is_perfect(tree->left);
	r_tree = binary_tree_is_perfect(tree->right);

	if ((l_height - r_height) == 0)
		if (l_tree && r_tree)
			return (1);

	return (0);
}


/**
 * get_height - recursivly calculate the height of tree
 * @tree: the root node of the tree
 * Return: the height of the tree
 */
size_t get_height(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (tree == NULL)
		return (0);

	l_height += get_height(tree->left);
	r_height += get_height(tree->right);

	if (l_height > r_height)
		return (++l_height);

	return (++r_height);
}
