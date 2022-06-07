#include "sort.h"

/**
* merge_sort - sorts an array of integers in ascending order
* @array: array that needs to be sorted
* @size: size of the array
*/
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;
	merge_array(array, size, tmp);
	free(tmp);
}

/**
* merge_array - divides the array recursively
* @array: array that is getting divided
* @size: size of the array
* @tmp: temporary array
*/
void merge_array(int *array, size_t size, int *tmp)
{
	int half;

	if (size < 2)
		return;
	half = size / 2;
	merge_array(array, half, tmp);
	merge_array(array + half, size - half, tmp);
	merge_all(array, size, half, tmp);
}

/**
* merge_all - sort, merge and print the array
* @array: array that needs to be sorted
* @size: size of the array
* @half: index of the middle of the array
* @tmp: temporary array
*/
void merge_all(int *array, int size, int half, int *tmp)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, half);
	printf("[right]: ");
	print_array(array + half, size - half);
	for (i = 0, j = half, k = 0; k < size; k++)
	{
		if (j == size)
		{
			tmp[k] = array[i];
			i++;
		}
		else if (i == half)
		{
			tmp[k] = array[j];
			j++;
		}
		else if (array[j] < array[i])
		{
			tmp[k] = array[j];
			j++;
		}
		else
		{
			tmp[k] = array[i];
			i++;
		}
	}
	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	printf("[Done]: ");
	print_array(tmp, size);
}
