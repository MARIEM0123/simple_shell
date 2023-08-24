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

