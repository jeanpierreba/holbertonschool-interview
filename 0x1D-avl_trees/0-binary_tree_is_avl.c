#include "binary_trees.h"

/**
* binary_tree_is_avl - checks if a binary tree is a valid avl tree
* @tree: tree we want to check
* Return: 1 if is a valid avl tree, 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int tree_height = 0;

	if (!tree)
		return (0);
	return (valid_avl(tree, INT_MIN, INT_MAX, &tree_height));
}

/**
* valid_avl - checks if a binary tree is a valid avl tree
* @tree: tree we want to check
* @min: minimum value of a subtree
* @max: maximum value of a subtree
* @tree_height: height of the tree
* Return: 1 is tree is valid, 0 otherwise
*/
int valid_avl(const binary_tree_t *tree, int min, int max, int *tree_height)
{
	int tmp1 = 0, tmp2 = 0;

	if (!tree)
		return (0);
	if (tree->n <= min || tree->n >= max)
		return (0);
	if (valid_avl(tree->left, min, tree->n, &tmp1) == 0 ||
		valid_avl(tree->right, tree->n, max, &tmp2) == 0)
		return (0);

	*tree_height = ((tmp1 > tmp2) ? tmp1 : tmp2) + 1;
	if (abs(tmp1 - tmp2) > 1)
		return (0);
	return (1);
}
