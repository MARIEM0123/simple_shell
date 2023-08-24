#include "shell.h"
/**
 * alias_c – the function
 * @DATA: parameter
 * @ch: the parameter
 * Return: there is a return
 */
int alias_c (DATA_t *DATA, char *ch)
{
	char *l, c;
	int x;

	l = _strchr(ch, '=');
	if (!l)
		return (1);
	c = *l;
	*l = 0;
	x = del_ndss(&(DATA->alias),
		nds_count(DATA->alias, str_nds(DATA->alias, ch, -1)));
	*l = c;
	return (x);
}

/**
 *  _alias_ - the function
 * @DATA: parameter
 *  Return: equal to 0
 */
int  _alias_(DATA_t *DATA)
{
	int k = 0;
	char *p = NULL;
	STRRUCT_L *nds = NULL;

	if (DATA->argc == 1)
	{
		nds = DATA->alias;
		while (nds)
		{
			alias_input(nds);
			nds = nds->too;
		}
		return (0);
	}
	for (k = 1; DATA->argv[k]; k++)
	{
		p = _strchr(DATA->argv[k], '=');
		if (p)
			alias_init(DATA, DATA->argv[k]);
		else
			alias_input(str_nds(DATA->alias, DATA->argv[k], '='));
	}

	return (0);
}

