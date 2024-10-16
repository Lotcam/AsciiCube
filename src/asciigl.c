#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"

int main() {
	screen_clear();
	printf("Hello, World!\n");
	usleep(1000000);
	screen_clear();
	printf("Goodbye, World!\n");
	return 0;
}
