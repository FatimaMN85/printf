#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int stlen(char *str);
void handleString(char *str, int *count);
void handleCharacter(int c, int *count);
bool InvalidFormat(const char *format);
int _printf(const char *format, ...);
void printInteger(int num, int *count);

#endif
