#include "shell.h"
/**
 * _strd – the function
 * @c: paraeter
 *
 * Return: there is a return
 */
char *_strd(const char *c)
{
	int x = 0;
	char *y;

	if (c == NULL)
		return (NULL);
	while (*c++)
		x++;
	y = malloc(sizeof(char) * x);
	if (!y)
		return (NULL);
	for (x++; x--;)
		y[x] = *--c;
	return (y);
}

