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

Point3D rotate_y(Point3D point, float angle);
Point3D rotate_x(Point3D point, float angle);
Point3D rotate_z(Point3D point, float angle);
void rotate_cube(float angle_x, float angle_y, float angle_z);
void screen_clear(void);
void project_3D_to_2D(Point3D point3D, Point2D *point2D);
void draw_cube(void);

#endif
