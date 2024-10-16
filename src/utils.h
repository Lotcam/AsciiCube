#ifndef UTILS_H
#define UTILS_H

#define SCREEN_WIDTH 120 
#define SCREEN_HEIGHT 40

void screen_clear(void);
void project_3D_to_2D(float x, float y, float z, int *x_2d, int *y_2d);
void draw_cube(void);

#endif
