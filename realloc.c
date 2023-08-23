#include "shell.h"
/**
 * _realloc – the function
 * @x: the pointer
 * @par1: the parameter
 * @par2: the parameter
 * Return: there is a return
 */
void *_realloc(void *x, unsigned int par1, unsigned int par2)
{
	char *y;

	if (!x)
		return (malloc(par2));
	if (!par2)
		return (free(x), NULL);
	if (par2 == par1)
		return (x);

	y = malloc(par2);
	if (!y)
		return (NULL);

	par1 = par1 < par2 ? par1 : par2;
	while (par1--)
		y[par1] = ((char *)x)[par1];
	free(x);
	return (y);
}

