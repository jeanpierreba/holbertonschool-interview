#include "menger.h"

/**
*
*
*
*
*/
void menger(int level)
{
	int size, row, column;

	size = pow(3, level);
	for (row = 0; row < size; row++)
	{
		for (column = 0; column < size; column++)
		{
			fill(row, column);
		}
		printf("\n");
	}
}

/**
*
*
*
*
*/
void fill(int row, int column)
{
	char character = '#';

	while (row || column)
	{
		if (row % 3 == 1 && column % 3 == 1)
		{
			character = ' ';
		}
		row = row / 3;
		column = column / 3;
	}
	printf("%c", character);
}