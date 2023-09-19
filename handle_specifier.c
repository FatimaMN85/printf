#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * handleSpecifier - handle the specifier
 * @s: the specifier
 * @args: argument
 * @count: counter
 * Return: 0
 */
int handleSpecifier(char s, va_list args, int *count)
{
	switch (s)
	{
		case 'c':
			handleCharacter(va_arg(args, int), count);
			break;
		case 's':
			handleString(va_arg(args, char *), count);
			break;
		case 'd':
		case 'i':
			printInteger(va_arg(args, int), count);
			break;
		case '%':
			write(1, "%", 1);
			(*count)++;
			break;
		default:
			write(1, &s, 1);
			(*count)++;
			break;
	}
	return (0);
}
