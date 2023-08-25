#include "shell.h"

/**
 * _eputchar - the function
 * @c: The paraeter
 * Return: != 0
 */
int _eputchar(char s)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (s == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (s != BUF_FLUSH)
		buf[i++] = s;
	return (1);
}
/**
 * _eputs - the function
 * @str: the parameter
 *
 * Return: there is no return
 */
void _eputs(char *c)
{
        int i = 0;

        if (!c)
                return;
        while (c[i] != '\0')
        {
                _eputchar(c[i]);
                i++;
        }
}
/**
 * _fileput - The function
 * @c: The parameter
 * @fd: Theparameter
 * Return: ther is a return depends on the case
 */
int _fileput(char c, int file)
{
	static int i;
	static char array[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(file, array, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		array[i++] = c;
	return (1);
}

/**
 * _fileputs -the function
 * @str: the parameter
 * @fd: the parameter
 * Return: ther is a return
 */
int _fileputs(char *c, int file)
{
	int i = 0;

	if (!c)
		return (0);
	while (*c)
	{
		i += _fileput(*c++, file);
	}
	return (i);
}

