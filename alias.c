#include "shell.h"
/**
 * alias_subt – the function to replace alias
 * @info: the parameter
 * Return: 1 ther is a return
 */
int alias_subt(DATA_t *DATA)
{
	int i;
	STRRUCT_L *nds;
	char *x;

	for (i = 0; i < 10; i++)
	{
		nds = str_nds(DATA->alias, DATA->argv[0], '=');
		if (!nds)
			return (0);
		free(DATA->argv[0]);
		x = _strchr(nds->str, '=');
		if (!x)
			return (0);
		x = _strdup(x + 1);
		if (!x)
			return (0);
		DATA->argv[0] = x;
	}
	return (1);
}

/**
 * alias_input – the function
 * @nds: the parameter
 * Return: there is a return
 */
int alias_input(STRRUCT_L *nds)
{
	char *x = NULL;
char *b = NULL;

	if (nds)
	{
		x = _strchr(nds->str, '=');
		for (b = nds->str; b <= x; b++)
		_putchar(*b);
		_putchar('\'');
		_puts(x + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * alias_init- the function
 * @DATA: parameter
 * @c: the parameter
 * Return: ther is a return
 */
int alias_init (DATA_t *DATA, char *c)
{
	char *x;

	x = _strchr(c, '=');
	if (!x)
		return (1);
	if (!*++x)
		return (alias_c(DATA, c));

	alias_c(DATA, c);
	return (add_nds_z(&(DATA->alias), c, 0) == NULL);
}
/**
 * nds_count – the function 
 * @par1: parameter
 * @nds: poarameter
 * Return: there is a return
 */
ssize_t nds_count(STRRUCT_L *par1, STRRUCT_L *nds)
{
	size_t k = 0;

	while (par1)
	{
		if (par1 == nds)
			return (k);
		par1 = par1->too;
		k++;
	}
	return (-1);
}

