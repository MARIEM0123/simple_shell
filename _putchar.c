#include <unistd.h>
#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _pputchar – the function
 * @c: The parameter
 * Return: there is a return
 */
int _pputchar(char c)
{
	static int k;
	static char array[MAXIMUM_BYTE_NUM];

	if (c == ZERO_NUM || k >= MAXIMUM_BYTE_NUM)
	{
		write(2, array, k);
		k = 0;
	}
	if (c != ZERO_NUM)
		array[k++] = c;
	return (1);
}

