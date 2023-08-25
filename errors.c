#include "shell.h"

/**
 * _eputs - the function
 * @str: the parameter
 *
 * Return: there is no return
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - the function
 * @c: The paraeter
 * Return: != 0
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _fileput - The function
 * @c: The parameter
 * @fd: Theparameter
 * Return: ther is a return depends on the case
 */
int _fileput(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _fileputs -the function
 * @str: the parameter
 * @fd: the parameter
 * Return: ther is a return
 */
int _fileputs(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _fileput(*str++, fd);
	}
	return (i);
}

