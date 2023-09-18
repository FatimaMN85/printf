#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: argument
 *
 * Return: the number of charcters
 */
int _printf(const char *format, ...)
{
	int count;
	va_list args;

	count = 0;
	va_start(args, format);
	if (InvalidFormat(format))
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					handleCharacter(va_arg(args, int), &count);
					break;
				case 's':
					handleString(va_arg(args, char *), &count);
					break;
				case 'd' || 'i':
					handleInteger(va_arg(args, int), &count);
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
				default:
					write(1, format - 1, 2);
					count += 2;
					break;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
