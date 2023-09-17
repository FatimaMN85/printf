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
	va_list args;
	int count, i;
	char c;
	char *str;
	va_start(args, format);

	i = 0;
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						c = va_arg(args, int);
						write(1, &c, 1);
						count++;
						break;
					}
				case 's':
					{
						str = va_arg(args, char *);
						while (str[i])
						{
							write(1, &str[i], 1);
							i++;
							count++;
						}
						break;
					}
				case '%':
					{
						write(1, "%", 1);
						count++;
						break;
					}
				default:
					write(1, format, 1);
					count++;
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
