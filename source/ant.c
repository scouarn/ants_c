#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <ezGfx/ezErr.h>

#include "ant.h"
#include "grid.h"
#include "util.h"


Ant* ant_list = NULL;


void ant_spawn(unsigned int x, unsigned int y) {

	Ant* ant = malloc( sizeof(Ant) );

	ant->x = x;
	ant->y = y;
	ant->hp = 100;
	ant->stack = NULL;
	ant_push(ant, ant_action_wander);

	ant->next = ant_list;
	ant->prev = NULL;

	if (ant_list) ant_list->prev = ant;

	ant_list = ant;
}


void ant_remove(Ant* ant) {

	if (ant == NULL) return;

	Ant* next = ant->next;
	Ant* prev = ant->prev;

	if (prev) prev->next = next;
	if (next) next->prev = prev;

	while (ant->stack) {
		ant_pop(ant);
	}

	free(ant);
}


void ant_update(Ant* ant) {
	ERR_assert(ant->x < COLS && ant->y < ROWS, "Ant wandered out of the grid !");


	Ant_action* action = ant_current(ant);

	if (action != NULL) action(ant);

}


Ant_action* ant_current(Ant* ant) {

	if (ant->stack) {
		return ant->stack->action;
	}
	else {
		return NULL;
	}

}

void ant_push(Ant* ant, Ant_action* state) {

	Ant_stack_node *new = malloc( sizeof(Ant_stack_node) );

	new->next = ant->stack;
	new->action = state;

	ant->stack = new;
}


void ant_pop(Ant* ant) {
		
	if (ant->stack) {
		Ant_stack_node* next = ant->stack->next;
		free(ant->stack);
		ant->stack = next;
	}

}




void ant_random_walk(Ant* ant) {

	int dx = randint(-1, 1);
	int dy = randint(-1, 1);

	unsigned int x = ant->x + dx;
	unsigned int y = ant->y + dy;

	if ((dx == 0 && dy == 0) /* staying in place is valid */
	 ||	pos_valid(x, y)) {
		ant->x += dx;
		ant->y += dy;
		return;
	}

}




void ant_action_dead(Ant* ant) {

}

void ant_action_wander(Ant* ant) {
	ant_random_walk(ant);
}

void ant_action_eat(Ant* ant) {

}

void ant_action_attack(Ant* ant) {

}

void ant_action_follow(Ant* ant) {

}




