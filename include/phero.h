#ifndef _PHERO_H_
#define _PHERO_H_


typedef struct {
	float dir[8];
	int dx, dy;
	float weight;
} Phero;

/* POST : set every direction weights to zero and call phero_init */
/* MOD : phero */
void phero_init(Phero *phero);

/* POST : if x,y is on a border the weights pointing toward
	the edge are set to zero */
/* MOD : phero */
void phero_border(Phero *phero, unsigned int x, unsigned int y);

/* POST : reduce the strenght of the pheromone (DISPERSION), 
	compute the new dx,dy and the weight  */
/* MOD : phero */
void phero_update(Phero *phero);



#endif /* phero_h */