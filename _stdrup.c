#include "shell.h"
/**
 * _strdup – the function
 * @c: paraeter
 *
 * Return: there is a return
 */
char *_strdup(const char *c)
{
	int x = 0;
	char *y;

	if (c == NULL)
		return (NULL);
	while (*c++)
		x++;
	y = malloc(sizeof(char) * (x + 1));
	if (!y)
		return (NULL);
	for (x++; x--;)
		y[x] = *--c;
	return (y);
}

