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
	int count;
	char c, *str;

	count = 0;
	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case '\0':
					break;
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
						if (str == NULL)
						{
							write(1, "(null)", 6);
							count+= 6;
						}
						else
						{
							write(1, str, stlen(str));
							count += stlen(str);
						}
						break;
					}
				case '%':
					{
						write(1, format, 1);
						count++;
						break;
					}
				default:
					write(1, "%", 1);
					count++;
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
