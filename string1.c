#include "shell.h"


/**
 * _strdup - the function
 * @c: the parameter
 * Return: ther is a return
 */
char *_strdup(const char *c)
{
	int l = 0;
	char *x;

	if (c == NULL)
		return (NULL);
	while (*c++)
		l++;
	x = malloc(sizeof(char) * (l + 1));
	if (!x)
		return (NULL);
	for (l++; l--;)
		x[l] = *--c;
	return (x);
}
/**
 * _strcpy - the function
 * @P1: the parameter
 * @P2: the parameter
 * Return: there is a return
 */
char *_strcpy(char *P1, char *P2)
{
        int i = 0;

        if (P1 == P2 || P2 == 0)
                return (P1);
        while (P2[i])
        {
                P1[i] = P2[i];
                i++;
        }
        P1[i] = 0;
        return (P1);
}
/**
 * _puts - the function
 * @str: theparameter
 * Return: there is no return
 */
void _puts(char *c)
{
	int k = 0;

	if (!c)
		return;
	while (c[k] != '\0')
	{
		_putchar(c[k]);
		k++;
	}
}

/**
 * _putchar - the function
 * @c: The parameter
 * Return: there is a return
 */
int _putchar(char str)
{
	static int i;
	static char array[WRITE_BUF_SIZE];

	if (str == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, array, i);
		i = 0;
	}
	if (str != BUF_FLUSH)
		array[i++] = str;
	return (1);
}

