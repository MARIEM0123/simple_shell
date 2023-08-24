#include "shell.h"
/**
 * varias_subt – the function to replace variables
 * @DATA: the parameter
 *
 * Return: 1 if replaced, 0 otherwise
 */
int varias_subt(DATA_t *DATA)
{
	int i = 0;
	STRRUCT_L *nds;

	for (i = 0; DATA->argv[i]; i++)
	{
		if (DATA->argv[i][0] != '$' || !DATA->argv[i][1])
			continue;

		if (!_strcmp(DATA->argv[i], "$?"))
		{
			str_chg(&(info->argv[i]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			str_chg(&(info->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		nds = str_nds(info->env, &info->argv[i][1], '=');
		if (nds)
		{
			str_chg(&(info->argv[i]),
					_strdup(_strchr(nds->str, '=') + 1));
			continue;
		}
		str_chg(&DATA->argv[i], _strdup(""));

	}
	return (0);
}

