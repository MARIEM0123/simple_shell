#include "shell.h"

/**
 * is_lchx - the function
 * @data: the parameter
 * @arr: the parameter
 * @p: the parameter
 * Return: there is a return
 */
int is_lchx(info_t *data, char *arr, size_t *p)
{
	size_t j = *p;

	if (arr[j] == '|' && arr[j + 1] == '|')
	{
		arr[j] = 0;
		j++;
		data->arr_cmdt = NUM_ONE;
	}
	else if (arr[j] == '&' && arr[j + 1] == '&')
	{
		arr[j] = 0;
		j++;
		data->arr_cmdt = NUM_TWO;
	}
	else if (arr[j] == ';')
	{
		arr[j] = 0;
		data->arr_cmdt = NUM_TREE;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * ver_ch - the function
 * @data: the parameter
 * @arr: the parameter
 * @p: the parameter
 * @i: the parameter
 * @len: the parameter
 * Return: there us a freturn
 */
void ver_ch(info_t *data, char *arr, size_t *p, size_t i, size_t en)
{
	size_t j = *p;

	if (data->arr_cmdt == NUM_TWO)
	{
		if (data->etat)
		{
			arr[i] = 0;
			j =en;
		}
	}
	if (data->arr_cmdt == NUM_ONE)
	{
		if (!data->etat)
		{
			arr[i] = 0;
			j = en;
		}
	}

	*p = j;
}

/**
 * _alias_md - the function
 * @dta: the parameter
 * Return: the return is != 0
 */
int alias_md(info_t *data)
{
	int i;
	data_l *nds;
	char *p;

	for (i = 0; i < 10; i++)
	{
		nds = node_starts_with(data->alias, data->argv[0], '=');
		if (!nds)
			return (0);
		free(data->argv[0]);
		p = hr_str(nds->rst, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		data->argv[0] = p;
	}
	return (1);
}

/**
 * vars_md - the function
 * @data: the parameter
 * Return: there is a return
 */
int vars_md(info_t *data)
{
	int i = 0;
	data_l *nds;

	for (i = 0; data->argv[i]; i++)
	{
		if (data->argv[i][0] != '$' || !data->argv[i][1])
			continue;

		if (!_strcmp(data->argv[i], "$?"))
		{
			string_md(&(data->argv[i]),
					_strdup(n_conv(data->etat, 10, 0)));
			continue;
		}
		if (!_strcmp(data->argv[i], "$$"))
		{
			string_md(&(data->argv[i]),
					_strdup(n_conv(getpid(), 10, 0)));
			continue;
		}
		nds = node_starts_with(data->dt, &data->argv[i][1], '=');
		if (nds)
		{
			string_md(&(data->argv[i]),
					_strdup(hr_str(nds->rst, '=') + 1));
			continue;
		}
		string_md(&data->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * string_md - the function
 * @P1: parameter
 * @P2: parameter
 * Return: the return is !=0
 */
int string_md(char **P1, char *P2)
{
	free(*P1);
	*P1 = P2;
	return (1);
}

