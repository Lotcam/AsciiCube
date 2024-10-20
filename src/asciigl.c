#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"

void parse_args(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-c") == 0 && i + 1 < argc) {
			set_character(argv[i + 1][0]);
		}
	}
}


int main(int argc, char *argv[]) {
	parse_args(argc, argv);
	float angle = 0.0;
	while (1) {	
        	screen_clear();
		rotate_cube(angle, angle, angle);
        	draw_cube();
		fflush(stdout);
        	angle += 0.1;
        	usleep(100000); 
        	printf("\x1b[%d;%dH", SCREEN_HEIGHT, 0);
	}
	return 0;
}
