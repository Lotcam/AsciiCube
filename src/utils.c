#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"


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
	Point2D cube_vertices_2D[8];
	for (int i = 0; i < 8; i++) {
		project_3D_to_2D(rotated_cube_vertices[i], &cube_vertices_2D[i]);
	}
	for (int i = 0; i < 8; i++) {
		printf("\x1b[%d;%dH", (int)cube_vertices_2D[i].y, (int)cube_vertices_2D[i].x); 
		printf("@");
	}
	printf("\x1b[0;0H");
}


