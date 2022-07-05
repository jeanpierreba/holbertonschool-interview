#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>


void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
int max_number(int *array, int size);
void sort_array(int *array, int size, int number);

#endif
