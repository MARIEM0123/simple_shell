#include "shell.h"
/**
 * del_ndss – the function
 * @h: parameter
 * @k: parameter
 * Return: there is a return
 */
int del_ndss(STRRUCT_L **h, unsigned int k)
{
	STRRUCT_L *nds, *x_nds;
	unsigned int i = 0;

	if (!h || !*h)
		return (0);

	if (!k)
	{
		nds = *h;
		*h = (*h)->too;
		free(nds->str);
		free(nds);
		return (1);
	}
	nds = *h;
	while (nds)
	{
		if (i == k)
		{
			x_nds->too = nds->too;
			free(nds->str);
			free(nds);
			return (1);
		}
		i++;
		x_nds = nds;
		nds = nds->too;
	}
	return (0);
}

