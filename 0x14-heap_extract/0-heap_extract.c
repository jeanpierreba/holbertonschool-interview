#include "binary_trees.h"

/**
* heap_extract - extracts the root node of a Max Binary Heap
* @root: double pointer to the root node of the heap
* Return: value stored in the root node
*/
int heap_extract(heap_t **root)
{
	binary_tree_t *last_node, *first_node;
	int extract;

	if (!root || !*root)
		return (0);
	first_node = *root;
	if (!first_node->left && !first_node->right)
	{
		extract = first_node->n;
		free(first_node);
		*root = NULL;
		return (extract);
	}
	first_node = *root;
	extract = first_node->n;
	last_node = get_last_node(*root);
	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;
	last_node->left = first_node->left;
	last_node->right = first_node->right;
	last_node->parent = first_node->parent;
	if (first_node->left)
		first_node->left->parent = last_node;
	if (first_node->right)
		first_node->right->parent = last_node;
	*root = last_node;
	free(first_node);
	heapify(*root);
	return (extract);
}

/**
* get_last_node - get the last node
* @root: first node of the three
* Return: last node
*/
binary_tree_t *get_last_node(heap_t *root)
{
	int nodes, heap_size;
	binary_tree_t *last_node = NULL;

	heap_size = get_nodes(root);
	for (nodes = 1; nodes <= heap_size; nodes <<= 1)
		nodes >>= 2;
	for (last_node = root; nodes > 0; nodes >>= 1)
	{
		if (heap_size && nodes)
			last_node = last_node->right;
		else
			last_node = last_node->left;
	}
	return (last_node);
}

/**
* get_nodes - get the number of nodes
* @root: first node of three
* Return: number of nodes
*/
int get_nodes(heap_t *root)
{
	int left, right;

	if (!root)
		return (0);
	left = get_nodes(root->left);
	right = get_nodes(root->right);
	return (1 + left + right);
}

/**
* heapify - heapifies
* @root: first node of the three
*/
void heapify(binary_tree_t *root)
{
	binary_tree_t *new_node;
	int tmp;

	while (1)
	{
		if (!root->left)
			break;
		else if (!root->right)
			new_node = root->left;
		else
		{
			if (root->left->n >= root->right->n)
				new_node = root->left;
			else
				new_node = root->right;
		}
		if (root->n >= new_node->n)
			break;
		tmp = root->n;
		root->n = new_node->n;
		new_node->n = tmp;
		root = new_node;
	}
}
