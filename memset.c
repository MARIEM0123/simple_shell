#include "shell.h"

/**
 * _memset – the function
 * @c: the parameter
 * @a: the parameter
 * @m: the parameter number
 * Return: there is a return
 */
char *_memset(char *c, char a, unsigned int m)
{
	unsigned int k;

	for (k = 0; k < m; k++)
		c[k] = a;
	return (c);
}

