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

