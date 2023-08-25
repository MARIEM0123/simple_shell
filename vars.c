#include "shell.h"

/**
 * is_chain - the function
 * @info: the parameter
 * @buf: the parameter
 * @p: the parameter
 * Return: there is a return
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->arr_cmdt = NUM_ONE;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->arr_cmdt = NUM_TWO;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		info->arr_cmdt = NUM_TREE;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - the function
 * @info: the parameter
 * @buf: the parameter
 * @p: the parameter
 * @i: the parameter
 * @len: the parameter
 * Return: there us a freturn
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->arr_cmdt == NUM_TWO)
	{
		if (info->etat)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->arr_cmdt == NUM_ONE)
	{
		if (!info->etat)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - the function
 * @info: the parameter
 * Return: the return is != 0
 */
int replace_alias(info_t *info)
{
	int i;
	data_l *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->rst, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - the function
 * @info: the parameter
 * Return: there is a return
 */
int replace_vars(info_t *info)
{
	int i = 0;
	data_l *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(info->etat, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->dt, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
					_strdup(_strchr(node->rst, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - the function
 * @old: parameter
 * @new: parameter
 * Return: the return is !=0
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

