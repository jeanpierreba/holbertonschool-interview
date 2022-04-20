#include "sort.h"

/**
* heap_sort - Heap sort algorithm to sort an array of ints
* @array: array we want to sort
* @size: size of the array
*/
void heap_sort(int *array, size_t size)
{
	int i, j;

	if (!size)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i > 0; i--)
	{
		j = array[0];
		array[0] = array[i];
		array[i] = j;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
* heapify - makes an array into a heap
* @array: pointer to the array
* @n: size of the array
* @i: index
* @size: total size
*/
void heapify(int *array, size_t n, int i, size_t size)
{
	int left = 2 * i + 1, right = 2 * i + 2, bigger = i, tmp;

	if (left < (int) n && array[left] > array[bigger])
		bigger = left;
	if (right < (int) n && array[right] > array[bigger])
		bigger = right;
	if (bigger != i)
	{
		tmp = array[i];
		array[i] = array[bigger];
		array[bigger] = tmp;
		print_array(array, size);
		heapify(array, n, bigger, size);
	}
}
