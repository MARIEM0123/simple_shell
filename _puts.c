#include "shell.h"
/**
 * _puts - the function to print a string
 * @str: the string to print
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar ('\n');
}
/**
 * _pputs – the funchion
 * @c: the parameter
 * Return: No return
 */
void _pputs(char *c)
{
	int k = 0;

	if (!c)
		return;
	while (c[k] != '\0')
	{
		_pputchar(c[k]);
		k++;
	}
}

