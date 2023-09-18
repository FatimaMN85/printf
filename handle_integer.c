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
	int len = 0, i;
	int is_negative = 0;

	for (len = 0; buffer[len] != '0'; len++)
	{
		if (num < 0)
		{
			is_negative = 1;
			num = -num;
		}
		if(num > 0)
		{
			buffer[len++] = '0' + (num % 10);
			num /= 10;
		}
		while (len > 0)
		{
			write(1, &buffer[--len], 1);
			(*count)++;
		}
	}
	if (is_negative)
	{
		buffer[len++] = '-';
	}
}