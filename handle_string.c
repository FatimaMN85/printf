#include "main.h"
#include <stdarg.h>

/**
 * handleString - handle the string
 * @str: the string
 * @count: the pointer
 */
void handleString(char *str, int *count)
{
	int x;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		*count += 6;
	}
	else
	{
		x = stlen(str);
		write(1, str, x);
		*count += x;
	}
}
