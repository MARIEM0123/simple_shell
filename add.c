#include "shell.h"
/**
 * add_nds_z – the function
 * @h: tha parameter
 * @ch: the parameter
 * @num: parameyer
 * Return: there is a return
 */
STRRUCT_L *add_nds_z(STRRUCT_L **h, const char *ch, int num)
{
	STRRUCT_L *new_nds, *nds;

	if (!h)
		return (NULL);

	nds = *h;
	new_nds = malloc(sizeof(STRRUCT_L));
	if (!new_nds)
		return (NULL);
	_memset((void *)new_nds, 0, sizeof(STRRUCT_L));
	new_nds->num = num;
	if (ch)
	{
		new_nds->str = _strd(ch);
		if (!new_nds->str)
		{
			free(new_nds);
			return (NULL);
		}
	}
	if (nds)
	{
		while (nds->too)
			nds = nds->too;
		nds->too = new_nds;
	}
	else
		*h = new_nds;
	return (new_nds);
}

