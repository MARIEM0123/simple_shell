#include "shell.h"
/**
 * stline – the function
 * @h: the parameter
 * Return: is the lenght
 */
int stline(char *h)
{
	int k = 0;

	if (!h)
		return (0);

	while (*h++)
		k++;
	return (k);
}
/**
 **_strncat – the function
 *@par1: the parameter1
 *@par2: the parameter2
 *@count: the parameter
 *Return: the concatenated string
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

