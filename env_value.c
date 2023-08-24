#include "shell.h"
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

