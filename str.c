#include "shell.h"
/**
 * stline – the function
 * @h: the parameter
 * Return: is the lenght
 */
int stline(char *h)
{
	int k = 0;

	if (!h)
		return (0);

	while (*h++)
		k++;
	return (k);
}

