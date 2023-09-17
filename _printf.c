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
	char c, *str;

	count = 0;
	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
					{
						write(1, "(null)", 6);
						count += 6;
					}
					else
					{
						write(1, str, stlen(str));
						count += stlen(str);
					}
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
