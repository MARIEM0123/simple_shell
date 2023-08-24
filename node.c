#include "shell.h"
/**i
* str_nds – the funtion
 * @node: parameter
 * @prefix: parameter
 * @c: the parameter
 * Return: ther isb a return
 */
STRRUCT_L *str_nds(STRRUCT_L *nds, char *l, char c)
{
	char *x = NULL;

	while (nds)
	{
		x = starts_with(nds->str, l);
		if (x && ((c == -1) || (*x == c)))
			return (nds);
		nds = nds->next;
	}
	return (NULL);
}

