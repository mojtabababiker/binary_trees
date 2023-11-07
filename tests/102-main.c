#include "../binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    binary_tree_t *root_2;
    int complete;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 128);
    root->left->left = binary_tree_node(root->left, 10);
    root->left->right = binary_tree_node(root->left, 54);
    /*root->right->left = binary_tree_node(root->right, 25);*/
    root->right->right = binary_tree_node(root->right, 402);
    root->left->left->left = binary_tree_node(root->left->left, 43);
    root->left->left->right = binary_tree_node(root->left->left, 43);
    binary_tree_print(root);
    complete = binary_tree_is_complete(root);
    printf("Is %d complete: %d\n", root->n, complete);

    printf("===================================\n");
    root_2 = binary_tree_node(NULL, 98);
    binary_tree_print(root_2);
    complete = binary_tree_is_complete(root_2);
    printf("Is %d complete: %d\n", root_2->n, complete);
    return (0);
}
