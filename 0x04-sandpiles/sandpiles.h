#ifndef _SANDPILES_
#define _SANDPILES_

#include <stdio.h>
#include <stdlib.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int check_stable(int grid1[3][3]);
void organize_sandpile(int grid1[3][3]);
void print_it(int grid[3][3]);

#endif
