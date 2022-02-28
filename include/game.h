#ifndef _GAME_H_
#define _GAME_H_

/* everything display/io related */

#include <ezGfx/ezGfx.h>

#include "grid.h"


void setup();
void draw(double dt);
void kill();
void keydown(EZ_Key_t* k);


#endif /* game_h */