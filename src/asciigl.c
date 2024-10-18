#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"

int main() {
	float angle = 0.0;
	int i = 0;
	while (1) {	
        	screen_clear();
		rotate_cube(angle, angle, angle);
        	draw_cube();
		fflush(stdout);
        	angle += 0.1;
        	usleep(200000); 
        	printf("\x1b[%d;%dH", SCREEN_HEIGHT, 0);
	}
	return 0;
}
