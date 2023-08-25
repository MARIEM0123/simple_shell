#include "shell.h"
/**
 * rm_env – the function
 * @DATA:  parameter
 * Return: equal to 0
 */
int rm_env(DATA_t *DATA)
{
	int k;

	if (DATA->argc == 1)
	{
		_pputs("Error message\n");
		return (1);
	}
	for (k = 1; k <= DATA->argc; k++)
		rmp_env(DATA, DATA->argv[k]);

	return (0);
}
/**
 * rmp_env – the function
 * @DATA: parameter
 *  Return: there is a return
 * @var: the string evn var property
 */
int rmp_env(DATA_t *DATA, char *x)
{
	STRRUCT_L *nds = DATA->evn;
	size_t k = 0;
	char *p;

	if (!nds || !x)
		return (0);

	while (nds)
	{
		p = abd(nds->str, x);
		if (p && *p == '=')
		{
			DATA->env_mod = del_ndss(&(DATA->evn), k);
			k = 0;
			nds = DATA->evn;
			continue;
		}
		nds = nds->too;
		k++;
	}
	return (DATA->env_mod);
}

