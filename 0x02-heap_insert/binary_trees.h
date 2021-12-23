#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *);
heap_t *heap_insert(heap_t **root, int value);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/**
* struct find_space_s - Struct to find an empty space at a Binary node
* @size: size of the node
* @node: node
*/
struct find_space_s
{
	int size;
	heap_t *node;
};

typedef struct find_space_s find_space_t;

find_space_t find_size(heap_t *node);
heap_t *swap_n(heap_t *node);
heap_t *insert_new_node(heap_t *parent);

#endif /* _BINARY_TREES_H_ */