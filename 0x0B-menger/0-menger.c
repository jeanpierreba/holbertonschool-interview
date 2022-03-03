#include "menger.h"

/**
* menger - draws a 2D Menger Sponge
* @level: level of the Menger Sponge to draw
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
* fill - fills the draw with #
* @row: rows
* @column: columns
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
