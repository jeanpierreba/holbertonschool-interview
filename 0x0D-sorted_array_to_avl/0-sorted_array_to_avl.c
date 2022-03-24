#include "binary_trees.h"

/**
* sorted_array_to_avl - convert an array to an avl tree
* @array: array we want to convert
* @size: size of the array
* Return: tree or null
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *new_tree;

	new_tree = add_node(array, 0, (int)size - 1);
	if (new_tree == NULL)
		return (NULL);
	return (new_tree);
}

/**
* create_new_node - create a new node of and avl tree
* @number: number to set to the node
* Return: new node or null
*/
avl_t *create_new_node(int number)
{
	avl_t *new_node;

	if (!number)
		return (NULL);

	new_node = malloc(sizeof(avl_t));
	if (!new_node)
		return (NULL);
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = number;
	return (new_node);
}

/**
* add_node - adds nodes recursively
* @array: pointer to array
* @beginning: beginning
* @end: end
* Return: parent node of the tree or null
*/
avl_t *add_node(int *array, int beginning, int end)
{
	avl_t *left_node, *right_node, *parent_node;
	size_t number = 0;

	if (beginning > end)
		return (NULL);
	number = (beginning + end) / 2;
	left_node = add_node(array, beginning, number - 1);
	right_node = add_node(array, number + 1, end);
	parent_node = create_new_node(array[number]);
	if (parent_node == NULL)
		return (NULL);
	parent_node->left = left_node;
	parent_node->right = right_node;
	if (left_node)
		left_node->parent = parent_node;
	if (right_node)
		right_node->parent = parent_node;
	return (parent_node);
}
