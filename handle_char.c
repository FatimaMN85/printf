#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * handleCharacter - Handle character
 * @c: character
 * @count: pointer
 */
void handleCharacter(int c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}
