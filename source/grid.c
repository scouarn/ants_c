#include <stdlib.h>

#include "grid.h"
#include "phero.h"

Cell grid[ROWS][COLS];

void grid_init() {

	for (int i = 0; i < COLS; i++)
	for (int j = 0; j < ROWS; j++) {

		phero_init(&grid[i][j].food);
		phero_init(&grid[i][j].home);
		phero_init(&grid[i][j].warn);
	}
}


int pos_valid(unsigned int x, unsigned int y) {

	if (x >= COLS || y >= ROWS)
		return 0;

	if (grid[x][y].type == CELL_ROCK
	 || grid[x][y].type == CELL_WATER
	 || grid[x][y].ant != NULL)
		return 0;

	return 1;
}


