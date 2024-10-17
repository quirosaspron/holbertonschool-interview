#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	new_node = insert_node(*root, value);
	if (!new_node)
		return (NULL);

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		int tmp = new_node->n;

		new_node->n = new_node->parent->n;
		new_node->parent->n = tmp;
		new_node = new_node->parent;
	}

	return (new_node);
}

/**
 * insert_node - Inserts a value into a Max Binary Heap
 *
 * @root: Pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *insert_node(heap_t *root, int value)
{
	heap_t *new_node;
	heap_t *parent = find_parent(root);

	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}

/**
 * find_parent - Finds the parent node for the new node to be inserted
 *
 * @root: Pointer to the root node of the Heap
 * Return: Pointer to the parent node, or NULL on failure
 */
heap_t *find_parent(heap_t *root)
{
	heap_t *parent;
	heap_t **queue;
	size_t front, rear, size;

	if (!root)
		return (NULL);

	size = tree_size(root);
	queue = malloc(size * sizeof(*queue));
	if (!queue)
		return (NULL);

	front = rear = 0;
	queue[rear++] = root;

	while (front < rear)
	{
		parent = queue[front++];
		if (!parent->left || !parent->right)
			break;
		queue[rear++] = parent->left;
		queue[rear++] = parent->right;
	}

	free(queue);
	return (parent);
}

/**
 * tree_size - Measures the size of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure
 * Return: The size of the tree
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}
