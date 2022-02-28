#ifndef _UTIL_H_
#define _UTIL_H_

/* POST : sigmoid(x) = 1 / (1 + e^-x) */
float sigmoid(float x);

/* POST : return a number n such that min <= n <= max */
int randint(int min, int max);

#endif /* util_h */

