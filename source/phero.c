#include "phero.h"
#include "grid.h"
#include "util.h"
#include <stdlib.h>

void phero_init(Phero *phero) {

	for (int i = 0; i < 8; i++)
		phero->dir[i] = 0.0;

	phero_update(phero);

}

void phero_border(Phero *phero, unsigned int x, unsigned int y) {

	if (x == 0) {
		phero->dir[7] = 0.0;
		phero->dir[6] = 0.0;
		phero->dir[5] = 0.0;
	}

	if (x >= COLS-1) {
		phero->dir[2] = 0.0;
		phero->dir[3] = 0.0;
		phero->dir[4] = 0.0;
	}

	if (y == 0) {
		phero->dir[7] = 0.0;
		phero->dir[0] = 0.0;
		phero->dir[1] = 0.0;
	}

	if (y >= ROWS-1) {
		phero->dir[3] = 0.0;
		phero->dir[4] = 0.0;
		phero->dir[5] = 0.0;
	}

}


void phero_update(Phero *p) {

	/* disperse */
	for (int i = 0; i < 8; i++)
		p->dir[i] *= DISPERSION;

	/* compute direction */
	float dmax = p->dir[0];
	int imax;

	for (imax = 1; imax < 8; imax++) {
		if (p->dir[imax] > dmax)
			dmax = p->dir[imax];
	}

	switch (imax) {
		
		case 0 : p->dx = 0; p->dy = -1;	break;

		case 1 : p->dx = 1; p->dy = -1;	break;

		case 2 : p->dx = 1; p->dy = 0;	break;

		case 3 : p->dx = 1; p->dy = 1;	break;

		case 4 : p->dx = 0; p->dy = 1;	break;

		case 5 : p->dx = -1; p->dy = 1;	break;

		case 6 : p->dx = -1; p->dy = 0;	break;

		case 7 : p->dx = -1; p->dy = -1; break;

		default :  p->dx = 0; p->dy = 0; break;

	}


	/* compute weight */
	float s = 0.0;
	for (int i = 0; i < 8; i++)
		s += p->dir[i];

	p->weight = sigmoid(s/4.0) * 2.0 - 1.0;
}
