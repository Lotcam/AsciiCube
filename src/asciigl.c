#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"

int main() {
	screen_clear();
	draw_cube();
	printf("\x1b[%d;%dH", SCREEN_HEIGHT, 0);
	return 0;
}
