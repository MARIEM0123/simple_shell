#include "shell.h"
#include <stddef.h>
/**
 * p_strings – the function
 * @p: the parameter
 * Return: ther is a return
 */
size_t p_strings(const STRRUCT_L *p)
{
	size_t k = 0;

	while (p)
	{
		_puts(p->str ? p->str : "(nil)");
		_puts("\n");
		p = p->too;
		k++;
	}
	return (k);
}

/**
 * NW_ennv – get the evnirnmnt
 * @DATA: the parameter
 * Return: tge return is 0
 */
int NW_ennv(DATA_t *DATA)
{
	p_strings(DATA->evn);
	return (0);
}

/**
 * ev_value – the function
 * @DATA: parameter
 * @pnn: nvironnement nomination
 *
 * Return: different that 0
 */
char *ev_value(DATA_t *DATA, const char *pnn)
{
	STRRUCT_L *nds = DATA->evn;
	char *x;

	while (nds)
	{
		x = abd(nds->str, pnn);
		if (x && *x)
			return (x);
		nds = nds->too;
	}
	return (NULL);
}
/**
 * listing_env – the function
 * @DATA: the parameter
 * Return: there is a return
 */
int listing_env(DATA_t *DATA)
{
	STRRUCT_L *nds = NULL;
	size_t k;

	for (k = 0; par_envv[k]; k++)
		add_nds_z(&nds, par_envv[k], 0);
	DATA->evn = nds;
	return (0);
}

