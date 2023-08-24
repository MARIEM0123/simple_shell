#include "shell.h"

/**
 * _strcpy – the function
 * @par1: the parameter
 * @par2: the parameter
 * Return: there is a return
 */
char *_strcpy(char *par1, char *par2)
{
	int i = 0;

	if (par1 == par2 || par2 == 0)
		return (par1);
	while (par2[i])
	{
		par1[i] = par2[i];
		i++;
	}
	par1[i] = 0;
	return (par1);
}

