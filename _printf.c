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
	int count = 0;
	va_list args;

	va_start(args, format);
	if (InvalidFormat(format))
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			handleSpecifier(*format, args, &count);
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
