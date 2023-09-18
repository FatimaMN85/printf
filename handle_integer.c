#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 *printInteger - prototype function that print numbers that
 *produces output according to a format.
 *
 * @num: parameter number.
 * @count: parameter number.
 *
 * Return: 1 if succes.
 *
*/

void printInteger(int num, int *count)
{
	char buffer[12];

	int len = 0;
	int is_negative = 0;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	do {
		buffer[len++] = '0' + (num % 10);
		num /= 10;
	} while (num > 0);
	if (is_negative)
	{
		buffer[len++] = '-';
	}
	while (len > 0)
	{
		write(1, &buffer[--len], 1);
		(*count)++;
	}
}
