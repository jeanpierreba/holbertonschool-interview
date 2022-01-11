#include "sandpiles.h"

/**
* sandpiles_sum - sums two sandpiles
* @grid1: first sandpile
* @grid2: second sandpile
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}
	while (check_stable(grid1) == 1)
		organize_sandpile(grid1);
}

/**
* check_stable - check if the sandpile is stable
* @grid1: sandpile that needs to be checked
* Return: 0 if stable, 1 otherwise
*/
int check_stable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (1);
		}
	}
	return (0);
}

/**
* organize_sandpile - organize the grid
* @grid1: grid that needs to be organized
*/
void organize_sandpile(int grid1[3][3])
{
	int j, i;
	int sand_grid[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	printf("=\n");
	print_it((grid1));
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i >= 0 && i < 2)
					sand_grid[i + 1][j] += 1;
				if (i > 0 && i <= 2)
					sand_grid[i - 1][j] += 1;
				if (j >= 0 && j < 2)
					sand_grid[i][j + 1] += 1;
				if (j > 0 && j <= 2)
					sand_grid[i][j - 1] += 1;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += sand_grid[i][j];
	}
}

/**
 * print_it - Print 3x3 grid
 * @grid: 3x3 grid
 */
void print_it(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
