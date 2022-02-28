#include "util.h"
#include <math.h>
#include <stdlib.h>

float sigmoid(float x) {
	return 1.0 / (1.0 + expf(-x));
}

/* https://stackoverflow.com/questions/9571738/picking-random-number-between-two-points-in-c */
int randint(int min, int max)  {
	return (int)((float)rand() / RAND_MAX * (max - min + 1)) + min;
}
