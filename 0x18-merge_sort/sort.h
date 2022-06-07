#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_array(int *array, size_t size, int *tmp);
void merge_all(int *array, int size, int half, int *tmp);

#endif
