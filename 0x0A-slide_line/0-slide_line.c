#include "slide_line.h"

/**
* slide_line - is able to slide & merge it to the left or to the right
* @line: pointer to an array of integers
* @size: size of the elements
* @direction: direction we want to merge to
* Return: 1 upon succes, 0 otherwise
*/
int slide_line(int *line, size_t size, int direction)
{
	switch (direction)
	{
		case 0:
			add(line, size);
			align(line, size);
			break;
		case 1:
			reverse(line, size);
			add(line, size);
			align(line, size);
			reverse(line, size);
			break;
		default:
			return (0);
	}
	return (1);
}

/**
* add - add numbers
* @list: pointer to an array of integers
* @size: size of the elements
*/
void add(int *list, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 1 + i; j < size; j++)
		{
			if (list[i] != 0 && list[j] != 0 && list[i] != list[j])
			{
				i = j;
				break;
			}
			if (list[i] != 0 && list[i] == list[j])
			{
				list[i] += list[i];
				list[j] = 0;
				break;
			}
		}
	}
}

/**
* align - align all numbers
* @list: pointer to an array of integers
* @size: size of the elements
*/
void align(int *list, size_t size)
{
	size_t i, j;

	for (i = 0, j = 0; i < size; i++)
	{
		if (list[i] != 0)
		{
			list[j] = list[i];
			j++;
		}
	}
	while (j < size)
	{
		list[j] = 0;
		j++;
	}
}

/**
* reverse - reverses the order of the array
* @list: pointer to an array of integers
* @size: size of the elements
*/
void reverse(int *list, size_t size)
{
	size_t i = 0, j = size - 1;
	int k;

	while (i < size / 2)
	{
		k = list[i];
		list[i] = list[j];
		list[j] = k;
		i++;
		j--;
	}
}
