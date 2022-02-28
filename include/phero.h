#ifndef _PHERO_H_
#define _PHERO_H_

#define DISPERSION 0.95


typedef struct {
	float dir[8];
	int dx, dy;
	float weight;
} Phero;


void phero_init(Phero *phero);
void phero_border(Phero *phero, unsigned int x, unsigned int y);

/* POST : reduce the strenght of the pheromone, 
	compute the new dx,dy and the weight  */
/* MOD : phero */
void phero_update(Phero *phero);



#endif /* phero_h */