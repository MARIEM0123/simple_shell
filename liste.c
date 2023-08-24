#include "shell.h"

/**
 * linked_lgnt – the function
 * @x: parameter
 * Return: size of list
 */
size_t linked_lgnt(const STRRUCT_L *x)
{
	size_t k = 0;

	while (x)
	{
		x = x->too;
		k++;
	}
	return (k);
}

