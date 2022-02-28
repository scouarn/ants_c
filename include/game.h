#ifndef _GAME_H_
#define _GAME_H_

/* everything display/io related */

#include <ezGfx/ezGfx.h>

#include "grid.h"

#define WIDTH 512
#define HEIGHT 512

#define CELL_W (WIDTH / COLS)
#define CELL_H (HEIGHT / ROWS)

#define UPDATE_FREQ 10

void setup();
void draw(double dt);
void kill();
void keydown(EZ_Key_t* k);


#endif /* game_h */