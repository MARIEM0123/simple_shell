#include "shell.h"
/**
 * NW_ennv – the function
 * @DATA: the parameter
 * Return: is equal to 0
 */
int NW_ennv(DATA_t *DATA)
{
	p_strings(DATA->evn);
	return (0);
}
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
 * ch_dir – the function
 * @DATA: the parameter
 * Return: equal to 0
 */
int ch_dir(DATA_t *DATA)
{
	char **array;

	array = DATA->argv;
	_puts("Error message \n");
	if (0)
		_puts(*array);
	return (0);
}
/**
 * _init_env – the function
 * @DATA: Parameter
 * @a: the parameter
 * @b: the parameter
 *  Return: there isb a return
 */
int _init_env(DATA_t *DATA, char *a, char *b)
{
	char *array = NULL;
	STRRUCT_L *nds;
	char *p;

	if (!a || !b)
		return (0);

	array = malloc(_strlen(a) + _strlen(b) + 2);
	if (!buf)
		return (1);
	_strcpy(array, a);
	_strcat(array, "=");
	_strcat(array, b);
	nds = DATA->evn;
	while (nds)
	{
		p = starts_with(node->str, a);
		if (p && *p == '=')
		{
			free(nds->str);
			nds->str = array;
			DATA-> env_mod = 1;
			return (0);
		}
		nds = nds->too;
	}
	add_nds_z(&(DATA->evn), array, 0);
	free(array);
	DATA->env_mod = 1;
	return (0);
}


