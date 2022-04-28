#include "search_algos.h"

/**
* advanced_binary - algorithm to search in an array
* @array: array we want to search in
* @size: size of the array
* @value: value we want to search in the array
* Return: index of the value, -1 otherwise
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (search_index(array, 0, size - 1, value));
}

/**
* search_index - looks for the index of the value
* @array: array we wan to search in
* @min: first element of the array
* @max: last value of the array
* @value: value we are looking for
* Return: index of value, -1 otherwise
*/
int search_index(int *array, int min, int max, int value)
{
	int middle, i;

	if (min > max)
		return (-1);

	printf("Searching in array: ");
	for (i = min; i < max; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
	if (min == max && array[max] == value)
		return (max);
	if (min == max && array[max] != value)
		return (-1);
	middle = min + (max - min) / 2;
	if ((middle == min || value != array[middle - 1]) && array[middle] == value)
		return (middle);
	if (array[middle] >= value)
		return (search_index(array, min, middle, value));
	return (search_index(array, middle + 1, max, value));
}
