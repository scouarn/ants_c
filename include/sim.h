#ifndef _SIM_H_
#define _SIM_H_

#include "ant.h"
#include "grid.h"
#include "phero.h"

/* POST : spawn some ants and init the grid */
/* MOD : grid, ant_list */
void sim_init();


/* POST : updates every cell in the grid,
	takes care of the border conditions,
	updates the ants */
/* MOD : grid, ant_list */
void sim_update();


#endif /* sim_h */

