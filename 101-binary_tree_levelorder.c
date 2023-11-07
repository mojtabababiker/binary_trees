#include "binary_trees.h"

queue *enqueue(queue **q, binary_tree_t *crnt_node);
queue *dequeue(queue **q);


/**
 * binary_tree_levelorder - travers a binary tree in a level order
 * @tree: a root pointer to tree
 * @func: a function pointer to be called for each travesred node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue *q = NULL, *temp = NULL;

	if (tree == NULL || func == NULL)
		return;

	q = enqueue(NULL, (binary_tree_t *)tree);
	if (!q)
		return;

	/* printf("%d the temp\n", temp->node->n); */
	while(q)
	{
		temp = dequeue(&q);
		(*func)(temp->node->n);
		if (temp->node->left)
		{
			if (q == NULL)
				q = enqueue(&q, temp->node->left);
			else
				enqueue(&q, temp->node->left);
		}
		if (temp->node->right)
		{
			if (q == NULL)
				q = enqueue (&q, temp->node->right);
			else
				enqueue(&q, temp->node->right);
		}
		free(temp);
	}
}

/**
 * enqueue - add to the queue or create a new queue
 * @q: the queue to add to it
 * @crnt_node: the node to add
 * Return: a pointer to the top node
 */
queue *enqueue(queue **q, binary_tree_t *crnt_node)
{
	queue *new = malloc(sizeof(queue));
	queue *temp = NULL;

	if (q == NULL || *q == NULL)
	{
		new->node = crnt_node;
		new->next = NULL;
		return (new);
	}

	temp = *q;
	while (temp->next)
	{
		temp = temp->next;
	}
	new->node = crnt_node;
	temp->next = new;
	new->next = NULL;
	return (new);
}

/**
 * dequeue - return the first node on the queue
 * @q: the queue to get the element from
 * Return: a pointer to the top node
 */
queue *dequeue(queue **q)
{
	queue *temp = NULL;

	if (q == NULL)
		return (NULL);

	temp = *q;
	*q = (*q)->next;
	return (temp);
}
