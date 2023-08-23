#include "shell.h"

/**
 **_strncat – the function
 *@par1: the parameter1
 *@par2: the second string
 *@count: the number of bytes
 *Return: there is a return
 */
char *_strncat(char *par1, char *par2, int count)
{
	int a, b;
	char *str = par1;

	a = 0;
	b = 0;
	while (par1[a] != '\0')
		a++;
	while (par2[b] != '\0' && b < count)
	{
		par1[a] = par2[b];
		a++;
		b++;
	}
	if (b < count)
		par1[a] = '\0';
	return (str);
}

