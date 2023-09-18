#include "main.h"
#include <stdbool.h>

/**
 * InvalidFormat - Check if the format string is invalid
 * @format: the format string
 *
 * Return: true if the format string is invalid, false otherwise.
*/

bool InvalidFormat(const char *format)
{
	if (!format || (format[0] == '%' && !format[1]))
		return (true);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (true);
	return (false);
}
