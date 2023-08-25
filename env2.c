#include "shell.h"
/**
 * init_new_env – the function
 * @DATA: parameter
 * @b: the parameter
 * @a: the parameter
 *  Return: equal to 0

 */
int init_new_env(DATA_t *DATA, char *b, char *a)
{
	char *array = NULL;
	STRRUCT_L *nds;
	char *p;

	if (!b || !a)
		return (0);

	array = malloc(stline(b) + stline(a) + 2);
	if (!array)
		return (1);
	_strcpy(array, b);
	_strcat(array, "=");
	_strcat(array, a);
	nds = DATA->evn;
	while (nds)
	{
		p = abd(nds->str, b);
		if (p && *p == '=')
		{
			free(nds->str);
			nds->str = array;
			DATA->env_mod = 1;
			return (0);
		}
		nds = nds->too;
	}
	add_nds_z(&(DATA->evn), array, 0);
	free(array);
	DATA->env_mod = 1;
	return (0);
}
/**
 * env_name – the function
 * @info: parameter
 * @l: the parameter
 *
 * Return: the value
 */
char *env_name(DATA_t *DATA, const char *l)
{
	STRRUCT_L *nds = DATA->evn;
	char *p;

	while (nds)
	{
		p = abd(nds->str, l);
		if (p && *p)
			return (p);
		nds = nds->too;
	}
	return (NULL);
}
/**
 * ch_cur_dir – the function
 * @DATA: parameter 
 * Return: equal to 0
 */
int ch_cur_dir(DATA_t *DATA)
{
	char *s, *x, array[1024];
	int xx;

	s = getcwd(array, 1024);
	if (!s)
		_puts("TODO: >>Error message <<\n");
	if (!DATA->argv[1])
	{
		x = env_name(DATA, "HOME=");
		if (!x)
			xx = chdir((x = env_name(DATA, "PWD=")) ? x : "/");
		else
			xx = chdir(x);
	}
	else if (_strcompare(DATA->argv[1], "-") == 0)
	{
		if (!env_name(DATA, "OLDPWD="))
		{
			_puts(s);

_putchar('\n');
			return (1);
		}
		_puts(env_name(DATA, "OLDPWD=")), _putchar('\n');
		xx = chdir((x = env_name(DATA, "OLDPWD=")) ? x : "/");
	}
	else
		xx = chdir(DATA->argv[1]);
	if (xx == -1)
	{
		err_output(DATA, "Error message ");
		_pputs(DATA->argv[1]), _pputchar('\n');
	}
	else
	{
		init_new_env(DATA, "OLDPWD", env_name(DATA, "PWD="));
		init_new_env(DATA, "PWD", getcwd(array, 1024));
	}
	return (0);
}
/**
 * err_output- the function
 * @DATA: the parameter
 * @x: parameter
 * Return: equal to 0 or 1
 */
void err_output(DATA_t *DATA, char *x)
{
	_pputs(DATA->fpnn);
	_pputs(": ");
	p_dtt(DATA-> num_lines, STDERR_FILENO);
	_pputs(": ");
	_pputs(DATA->argv[0]);
	_pputs(": ");
	_pputs(x);
}

