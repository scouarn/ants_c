#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <stdbool.h>

#include "game.h"
#include "sim.h"


#define WIDTH 512
#define HEIGHT 512

#define CELL_W (WIDTH / COLS)
#define CELL_H (HEIGHT / ROWS)



EZ_Image_t* canvas;
pthread_t sim_thread_id;
volatile int sim_thread_run;
void* sim_thread(void* arg);

bool do_show_grid;
bool do_show_ants;
bool do_show_phero;
bool do_show_terrain;


void setup() {

	canvas  = EZ_image_make(WIDTH, HEIGHT);

	EZ_frameRate(60.0);
	EZ_bind(canvas);
	EZ_draw2D_setBlendMode(ALPHA_FAST);

	srand(clock());
	// srand(10);

	do_show_grid = false;
	do_show_ants = true;
	do_show_phero = false;

	sim_init();
	pthread_create(&sim_thread_id, NULL, sim_thread, NULL);

}

void draw(double dt) {

	EZ_draw2D_clear(canvas, EZ_BW(51));

	for (int i = 0; i < COLS; i++)
	for (int j = 0; j < ROWS; j++) {

		if (do_show_phero) {
			int r = 255 * grid[i][j].warn.weight;
			int g = 255 * grid[i][j].home.weight;
			int b = 255 * grid[i][j].food.weight;

			EZ_Px_t col = EZ_RGB(r, g, b);

			EZ_draw2D_fillRect(canvas, col, i*CELL_W, j*CELL_H, CELL_W, CELL_H);
		}

		Ant* ant = grid[i][j].ant;
		if (do_show_ants && ant) {
			EZ_draw2D_line (canvas, EZ_WHITE, 
				ant->x * CELL_W, 
				ant->y * CELL_H, 
				(ant->x+1) * CELL_W, 
				(ant->y+1) * CELL_H
			);

			EZ_draw2D_line (canvas, EZ_WHITE, 
				ant->x * CELL_W, 
				(ant->y+1) * CELL_H,
				(ant->x+1) * CELL_W, 
				ant->y * CELL_H
			);
		}
	}


	if (do_show_grid) {
		for (int i = 1; i < COLS; i++)
			EZ_draw2D_line (canvas, EZ_WHITE, i*CELL_W, 0, i*CELL_W, HEIGHT);

		for (int i = 1; i < ROWS; i++)
			EZ_draw2D_line (canvas, EZ_WHITE, 0, i*CELL_H, WIDTH, i*CELL_H);
	}

}


void* sim_thread(void* arg) {

	sim_thread_run = 1;

	while (sim_thread_run) {
		sim_update();
		usleep(1000000/UPDATE_FREQ);
	}

	return NULL;
}




void kill() {
	sim_thread_run = 0;
	pthread_join(sim_thread_id, NULL);
	EZ_image_free(canvas);

}

void keydown(EZ_Key_t* k) {

	switch (k->code) {
		case K_ESCAPE : EZ_stop(); break;
		default : break;
	}
		
}
