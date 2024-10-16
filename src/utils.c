#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"

float cube_vertices[8][3] = {
	{-1.0, -1.0, -1.0},
	{1.0, -1.0, -1.0},
	{1.0, 1.0, -1.0},
	{-1.0, 1.0, -1.0},
	{-1.0, -1.0, 1.0},
	{1.0, -1.0, 1.0},
	{1.0, 1.0, 1.0},
	{-1.0, 1.0, 1.0}
};

void screen_clear() {
	printf("\x1b[2J");
	printf("\x1b[H");
}

void project_3D_to_2D(float x, float y, float z, int *x_2d, int *y_2d) {
	float distance = 2.0;
	float factor = distance / (distance + z);
	*x_2d = (int)(x * factor * 5) + (SCREEN_WIDTH / 2.0);
	*y_2d = (int)(y * factor * 5) + (SCREEN_HEIGHT / 2.0);
}

void draw_cube() {
	int x_2d[8], y_2d[8]; 
	for (int i = 0; i < 8; i++) {
		project_3D_to_2D(cube_vertices[i][0], cube_vertices[i][1], cube_vertices[i][2], &x_2d[i], &y_2d[i]);
	}
	for (int i = 0; i < 8; i++) {
		printf("\x1b[%d;%dH", y_2d[i], x_2d[i]);
		printf("@");
	}
	printf("\x1b[0;0H");
}


