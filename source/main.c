#include "game.h"


int main() {

	EZ_setCallback_init(setup);
	EZ_setCallback_draw(draw);
	EZ_setCallback_keyPressed(keydown);
	EZ_setCallback_kill(kill);

	EZ_start();
	EZ_join();

	return 0;
}