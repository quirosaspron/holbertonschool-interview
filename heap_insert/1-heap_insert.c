#include <stdlib.h>
#include "binary_trees.h"

/**
 * find_insert_position - Finds the next available position for insertion
 * using level-order traversal
 * @root: Pointer to the root of the heap
 * Return: Pointer to the parent node where a new child can be inserted
 */
heap_t *find_insert_position(heap_t *root)
{
	heap_t *queue[1024]; /* Simple array-based queue */
	int front = 0, rear = 0;

	queue[rear++] = root;

	while (front < rear)
	{
		heap_t *current = queue[front++];

		if (!current->left)
			return (current);
		if (!current->right)
			return (current);

		queue[rear++] = current->left;
		queue[rear++] = current->right;
	}

	return (NULL);
}

/**
 * heapify_up - Restore the Max Heap property after insertion
 * @node: Pointer to the newly inserted node
 */
void heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		int temp = node->n;

		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to insert
 * Return: Pointer to the newly inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *new_node;

	if (!root)
		return (NULL);

	/* If root is NULL, create the root node */
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	/* Find the next available position for the new node */
	parent = find_insert_position(*root);
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	/* Restore the Max Heap property */
	heapify_up(new_node);

	return (new_node);
}

