#include "shell.h"
/**
 * _strcat -  the function
 * @par1: the parameter
 * @par2: the parameter
 * Return: !=0
 */
char *_strcat(char *par1, char *par2)
{
	char *x = par1;

	while (*par1)
		par1++;
	while (*par2)
		*par1++ = *par2++;
	*par1 = *par2;
	return (x);
}
