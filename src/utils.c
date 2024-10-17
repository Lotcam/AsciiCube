#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"


void screen_clear() {
	printf("\x1b[2J");
	printf("\x1b[H");
}

void project_3D_to_2D(Point3D point3D, Point2D *point2D) {
	float distance = 5.0;
	float factor = distance / (distance + point3D.z);
	point2D->x = (int)(point3D.x * factor * 5) + (SCREEN_WIDTH / 2.0);
	point2D->y = (int)(point3D.y * factor * 5) + (SCREEN_HEIGHT / 2.0);
}

void draw_cube() {
	
	Point3D cube_vertices[] = {
		{-1, -1, -1},
		{1, -1, -1},
		{1, 1, -1},
		{-1, 1, -1},
		{-1, -1, 1},
		{1, -1, 1},
		{1, 1, 1},
		{-1, 1, 1}
	};

	Point2D cube_vertices_2D[8];
	for (int i = 0; i < 8; i++) {
		project_3D_to_2D(cube_vertices[i], &cube_vertices_2D[i]);
	}
	for (int i = 0; i < 8; i++) {
		printf("\x1b[%d;%dH", (int)cube_vertices_2D[i].y, (int)cube_vertices_2D[i].x); 
		printf("@");
	}
	printf("\x1b[0;0H");
}


