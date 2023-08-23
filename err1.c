#include "shell.h"
/**
 * _pprtchar – the function to get the info to print
 * @sh: The char
 * Return: the is a return
 */
int _pprtchar(char sh)
{
	static int a;
	static char array[MAXIMUM_BYTE_NUM];

	if (sh == MIINUSONE || a >= MAXIMUM_BYTE_NUM)
	{
		write(2, array, a);
		a = 0;
	}
	if (sh != MIINUSONE)
		array[a++] = sh;
	return (1);
}

/**
 * _entry – the function for the input
 * @str: the parameter
 * Return: ther is no return
 */
void _entry(char *c)
{
	int i = 0;

	if (!c)
		return;
	while (c[i] != '\0')
	{
		_pprtchar(c[i]);
		i++;
	}
}

