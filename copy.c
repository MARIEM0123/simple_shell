#include "shell.h"

/**
 **_strncpy – the function
 *@par1: the parameter 1
 *@par2: theparameter 2
 *@count: number of characters
 *Return: the new parameter
 */
char *_strncpy(char *par1, char *par2, int count)
{
	int a, b;
	char *str = par1;

	a = 0;
	while (par2[a] != '\0' && a < count - 1)
	{
		par1[a] = par2[a];
		a++;
	}
	if (a < count)
	{
		b = a;
		while (b < count)
		{
			par1[b] = '\0';
			b++;
		}
	}
	return (str);
}
/**
 * _strcompare  - the function
 * @c1: the parameter one
 * @c2: the parameter two
 *
 * Return: != 0
 */
int _strcompare (char *c1, char *c2)
{
	while (*c1 && *c2)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
	if (*c1 == *c2)
		return (0);
	else
		return (*c1 < *c2 ? -1 : 1);
}

#include "shell.h"

/**
 * _len_string – the function
 * @c: the parameter
 * Return: there is a return
 */
int _len_string(char *c)
{
	int k = 0;

	if (!c)
		return (0);

	while (*c++)
		k++;
	return (k);
}

