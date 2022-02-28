#ifndef _GRID_H_
#define _GRID_H_

#define ROWS 32
#define COLS 32

#include "ant.h"
#include "phero.h"


typedef enum {
	CELL_GROUND,
	CELL_ROCK,
	CELL_DIRT,
	CELL_WATER,
	CELL_FOOD,
	CELL_HOME,
} Cell_type;

typedef struct {
	Phero home;
	Phero food;
	Phero warn;
	Cell_type type;
	Ant* ant; /* occupant */
} Cell;

extern Cell grid[ROWS][COLS];

/* POST : set every pheromone in the grid to 0 */
/* MOD : grid */
void grid_init();

/* POST : true if and only if x,y is a valid position an ant can go */
int pos_valid(unsigned int x, unsigned int y);



#endif /* grid_h */