#include "main.h"

/**
 * stlen - the length of string
 * @str: string
 * Return: length
 */
int stlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
