#include "binary_trees.h"

/**
* heap_insert - inserts a value into a Max Binary Heap
* @root: double pointer to the root node of the Heap
* @value: value to store in the node to be inserted
* Return: pointer to the inserted node or NULL
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL, *lower = NULL;

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!(*root))
	{
		*root = new_node;
		return (new_node);
	}
	lower = insert_new_node(*root);
	if (!lower->left)
		lower->left = new_node;
	else
		lower->right = new_node;

	new_node->parent = lower;
	return (swap_n(new_node));
}

/**
* insert_new_node - Inserts a new node
* @root: pointer to the root node
* Return: pointer to the new node
*/
heap_t *insert_new_node(heap_t *root)
{
	find_space_t tmp;

	tmp = find_size(root);
	return (tmp.node);
}

/**
* find_size - finds the size of the node
* @node: pointer to the parent
* Return: struct with node size
*/
find_space_t find_size(heap_t *node)
{
	find_space_t left, right, tmp;

	tmp.node = node;
	tmp.size = 0;

	if (!node->left || !node->right)
		return (tmp);

	left = find_size(node->left);
	right = find_size(node->right);
	if (left.size <= right.size)
	{
		left.size += 1;
		return (left);
	}
	else
	{
		right.size += 1;
		return (right);
	}
}

/**
* swap_n - swap the position of two nodes
* @node: Node we want to change position
* Return: new position of node
*/
heap_t *swap_n(heap_t *node)
{
	int aux;
	heap_t *new = node;

	while (new->parent)
	{
		if (new->n > new->parent->n)
		{
			aux = new->n;
			new->n = new->parent->n;
			new->parent->n = aux;

			new = new->parent;
			continue;
		}
		return (new);
	}
	return (new);
}
