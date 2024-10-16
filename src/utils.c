#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 40

void screen_clear() {
	printf("\x1b[2J");
	printf("\x1b[H");
}

