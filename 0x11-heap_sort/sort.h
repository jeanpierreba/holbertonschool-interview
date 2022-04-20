#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <stdio.h>
#include <stdlib.h>

void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void heapify(int *array, size_t n, int i, size_t size);

#endif
