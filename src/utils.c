#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"

char character = '#';

void set_character(char c) {
	character = c;
}

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

Point3D rotate_y(Point3D point, float angle) {
	Point3D result;
	result.y = point.y;
	result.x = point.x * cos(angle) + point.z * sin(angle);
	result.z = -point.x * sin(angle) + point.z * cos(angle);
	return result;

}

Point3D rotate_x(Point3D point, float angle) {
	Point3D result;
	result.x = point.x;
	result.y = point.y * cos(angle) - point.z * sin(angle);
	result.z = point.y * sin(angle) + point.z * cos(angle);
	return result;
}

Point3D rotate_z(Point3D point, float angle) {
	Point3D result;
	result.z = point.z;
	result.x = point.x * cos(angle) - point.y * sin(angle);
	result.y = point.x * sin(angle) + point.y * cos(angle);
	return result;
}

Point3D rotated_cube_vertices[8];

void rotate_cube(float angle_x, float angle_y, float angle_z) {
	for (int i = 0; i < 8; i++) {
		Point3D vertex = cube_vertices[i];
		vertex = rotate_x(vertex, angle_x);
		vertex = rotate_y(vertex, angle_y);
		vertex = rotate_z(vertex, angle_z);
		rotated_cube_vertices[i] = vertex;
	}
}

void draw_line_direct(int x0, int y0, int x1, int y1) {
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx - dy;
	while (1) {
        	if (x0 >= 0 && x0 < SCREEN_WIDTH && y0 >= 0 && y0 < SCREEN_HEIGHT) {
            		printf("\x1b[%d;%dH%c", y0 + 1, x0 + 1, character);  // Move cursor and draw
        	}

        	if (x0 == x1 && y0 == y1) break;

        	int e2 = 2 * err;
        	if (e2 > -dy) {
            		err -= dy;
            		x0 += sx;
        	}
        	if (e2 < dx) {
            		err += dx;
            		y0 += sy;
        	}
    	}
}

void draw_cube_edges(Point2D cube_vertices_2D[8]) {
	int cube_edges[12][2] = {
       		{0, 1}, {1, 2}, {2, 3}, {3, 0}, // Back face
       		{4, 5}, {5, 6}, {6, 7}, {7, 4}, // Front face
		{0, 4}, {1, 5}, {2, 6}, {3, 7}  // Connecting edges
	};

	for (int i = 0; i < 12; i++) {
		int start = cube_edges[i][0];
		int end = cube_edges[i][1];
		draw_line_direct(cube_vertices_2D[start].x, cube_vertices_2D[start].y, 
				 cube_vertices_2D[end].x, cube_vertices_2D[end].y);
	    }
}

void screen_clear() {
	printf("\x1b[2J");
	printf("\x1b[H");
}

void project_3D_to_2D(Point3D point3D, Point2D *point2D) {
	float distance = 5.0;
	float factor = distance / (distance + point3D.z);
	point2D->x = (int)(point3D.x * factor * 10) + (SCREEN_WIDTH / 2.0);
	point2D->y = (int)(point3D.y * factor * 10) + (SCREEN_HEIGHT / 2.0);
}

void draw_cube() {
	Point2D cube_vertices_2D[8];
	for (int i = 0; i < 8; i++) {
		project_3D_to_2D(rotated_cube_vertices[i], &cube_vertices_2D[i]);
	}
	draw_cube_edges(cube_vertices_2D);
	printf("\x1b[0;0H");
}


