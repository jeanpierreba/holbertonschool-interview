#include "sort.h"

/**
* radix_sort - sorts an array of integers in ascending
* order using the Radix sort algorithm
* @array: array that has to be ordered
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	int number, maximum;

	if (size < 2)
		return;
	maximum = max_number(array, size);
	for (number = 1; maximum / number > 0; number *= 10)
	{
		sort_array(array, size, number);
		print_array(array, size);
	}
}

/**
* max_number - gets the maximum value
* @array: array
* @size: size of the array
* Return: maximum number of the array
*/
int max_number(int *array, int size)
{
	int i, maximum;

	for (maximum = array[0], i = 1; i < size; i++)
		if (array[i] > maximum)
			maximum = array[i];
	return (maximum);
}

/**
* sort_array - sorts the array
* @array: array that we need to sort
* @size: size of the array
* @number: maximum number
*/
void sort_array(int *array, int size, int number)
{
	int *output, i, counter[10] = {0};

	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	for (i = 0; i < size; i++)
		counter[(array[i] / number) % 10]++;
	for (i = 1; i < 10; i++)
		counter[i] += counter[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		output[counter[(array[i] / number) % 10] - 1] = array[i];
		counter[(array[i] / number) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}
