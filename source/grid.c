#include <stdlib.h>

#include "grid.h"
#include "phero.h"

Cell grid[ROWS][COLS];

int pos_valid(int x, int y) {

	if (x < 0 || y < 0 || x >= COLS || y >= ROWS)
		return 0;

	if (grid[x][y].type == CELL_ROCK
	 || grid[x][y].type == CELL_WATER)
		return 0;

	if (grid[x][y].ant != NULL)
		return 0;

	return 1;
}

