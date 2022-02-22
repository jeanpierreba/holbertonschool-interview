#ifndef SLIDE_LINE
#define SLIDE_LINE

#define SLIDE_RIGHT 1
#define SLIDE_LEFT 0

#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);
void add(int *list, size_t size);
void align(int *list, size_t size);
void reverse(int *list, size_t size);

#endif
