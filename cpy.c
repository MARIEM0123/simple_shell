#include "shell.h"

/**
 * _strcpy – the function
 * @par1: the parameter
 * @par2: the parameter
 * Return: there is a return
 */
char *_strcpy(char *par1, char *par2)
{
	int i = 0;

	if (par1 == par2 || par2 == 0)
		return (par1);
	while (par2[i])
	{
		par1[i] = par2[i];
		i++;
	}
	par1[i] = 0;
	return (par1);
}
/**
 * str_free – the function
 * @str: the parametre
 */
void str_free(char **str)
{
	char **c = str;

	if (!str)
		return;
	while (*str)
		free(*str++);
	free(c);
}
/**
 *lib_data - 	the function
 * @x: 
 * Return: void
 */
void lib_data(STRRUCT_L **x)
{
	STRRUCT_L *nds, *too_nds, *h;

	if (!x || !*x)
		return;
	h = *x;
	nds = h;
	while (nds)
	{
		too_nds = nds->too;
		free(nds->str);
		free(nds);
		nds = too_nds;
	}
	*x = NULL;
}
#include "shell.h"

/**
 * lib_pointer – the function
 * @x: parameter
 * Return: ther is a return
 */
int lib_pointer(void **x)
{
	if (x && *x)
	{
		free(*x);
		*x = NULL;
		return (1);
	}
	return (0);
}

