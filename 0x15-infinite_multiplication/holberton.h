#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int _putchar(char c);
char *operation(char *num1, char *num2, int length1, int length2);
int _is_number(char *number);
void _print(char *c);
void error_message(char *message);

#endif