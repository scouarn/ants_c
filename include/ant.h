#ifndef _ANTS_H_
#define _ANTS_H_

/* everything simulation related */


#include "phero.h"


struct Ant;
typedef void (Ant_action)(struct Ant* ant);

Ant_action ant_action_dead;
Ant_action ant_action_wander;
Ant_action ant_action_eat;
Ant_action ant_action_attack;
Ant_action ant_action_follow;

typedef struct Ant_stack_node {
	Ant_action *action;
	struct Ant_stack_node *next;

} Ant_stack_node;

typedef struct Ant {
	unsigned int x, y;
	int hp;
	
	Ant_stack_node *stack;

	struct Ant *next, *prev;
} Ant;


extern Ant* ant_list;


/* PRE : x,y is a valid position  */
/* POST : add to list ant with pos x,y */
void ant_spawn(unsigned int x, unsigned int y);

/* PRE : ant is in the list  */
/* POST : remove the ant from the list and free it */
void ant_remove(Ant* ant);

/* POST : update the ant's state an position, 
	lay pheromone on grid */
/* MOD : ant, grid */
void ant_update(Ant* ant);


/* POST : returns the action on the top of the ant's stack */
Ant_action* ant_current(Ant* ant);


/* POST : push new action on the ant's stack */
/* MOD : ant */
void ant_push(Ant* ant, Ant_action* action);

/* POST : remove action from the ant's stack */
/* MOD : ant */
void ant_pop(Ant* ant);

/* POST : make the ant choose a random direction
	and move to it if it's valid */
/* MOD : ant */
void ant_random_walk(Ant* ant);



/* POST : updates every cell in the grid,
	takes care of the border conditions,
	updates the ants */
/* MOD : grid, ant_list */
void sim_update();



#endif /* ants_h */