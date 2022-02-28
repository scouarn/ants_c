#include <stdlib.h>

#include "grid.h"
#include "ant.h"
#include "phero.h"


void sim_update() {

	/* border north and south */
	for (int i = 0; i < COLS; i++) {

		phero_border(&grid[i][0].food, i, 0);
		phero_border(&grid[i][0].home, i, 0);
		phero_border(&grid[i][0].warn, i, 0);

		phero_border(&grid[i][ROWS-1].food, i, ROWS-1);
		phero_border(&grid[i][ROWS-1].home, i, ROWS-1);
		phero_border(&grid[i][ROWS-1].warn, i, ROWS-1);
	}

	/* border east and west */
	for (int i = 0; i < ROWS; i++) {

		phero_border(&grid[0][i].food, 0, i);
		phero_border(&grid[0][i].home, 0, i);
		phero_border(&grid[0][i].warn, 0, i);

		phero_border(&grid[COLS-1][i].food, COLS-1, i);
		phero_border(&grid[COLS-1][i].home, COLS-1, i);
		phero_border(&grid[COLS-1][i].warn, COLS-1, i);

	}

	/* disperse and reset ant */
	for (int i = 0; i < COLS; i++)
	for (int j = 0; j < ROWS; j++) {

		grid[i][j].ant = NULL;

		phero_update(&grid[i][j].food);
		phero_update(&grid[i][j].home);
		phero_update(&grid[i][j].warn);
		phero_update(&grid[i][j].warn);

	}

		
	for (Ant* ant = ant_list; ant != NULL; ant = ant->next) {
		grid[ant->x][ant->y].ant = ant;
		ant_update(ant);
	}
	
}

