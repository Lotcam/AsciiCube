#ifndef UTILS_H
#define UTILS_H

#define SCREEN_WIDTH 120 
#define SCREEN_HEIGHT 40


typedef struct {
	float x, y, z;
} Point3D;

typedef struct {
	float x, y;
} Point2D;

void screen_clear(void);
void project_3D_to_2D(Point3D point3D, Point2D *point2D);
void draw_cube(void);

#endif
