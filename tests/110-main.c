#include "../binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int bst;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 128);
    root->left->left = binary_tree_node(root->left, 10);
    root->left->right = binary_tree_node(root->left, 54);
    root->right->left = binary_tree_node(root->right, 100);

    binary_tree_print(root);
    bst = binary_tree_is_bst(root);
    printf("Is %d bst: %d\n", root->n, bst);
    bst = binary_tree_is_bst(root->left);
    printf("Is %d bst: %d\n", root->left->n, bst);

    root->right->right = binary_tree_node(root->right, 497);
    binary_tree_print(root);
    bst = binary_tree_is_bst(root);
    printf("Is %d bst: %d\n", root->n, bst);

    root->left->left->left = binary_tree_node(root->left->left, 7);
    root->left->left->right = binary_tree_node(root->left->right, 17);

    root->left->right->left = binary_tree_node(root->left->right, 47);
    root->left->right->right = binary_tree_node(root->left->right, 56);

    root->right->left->left = binary_tree_node(root->right->left, 99);
    root->right->left->right = binary_tree_node(root->right->left, 117);

    root->right->right->left = binary_tree_node(root->right->right, 130);
    root->right->right->right = binary_tree_node(root->right->right, 556);

    binary_tree_print(root);
    bst = binary_tree_is_bst(root);
    printf("Is %d bst: %d\n", root->n, bst);

    return (0);
}
