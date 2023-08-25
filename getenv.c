#include "shell.h"

/**
 * get_environ - the function
 * @info: the parameter
 * Return:equal to 0
 */
char **get_environ(info_t *info)
{
	if (!info->prb || info->mod)
	{
		info->prb = list_to_strings(info->dt);
		info->mod = 0;
	}

	return (info->prb);
}

/**
 * _unsetenv - The function
 * @info: the parameter
 *  Return: there is a return
 * @var: the parameter
 */
int _unsetenv(info_t *info, char *var)
{
	data_l *node = info->dt;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = init_func(node->rst, var);
		if (p && *p == '=')
		{
			info->mod= delete_node_at_index(&(info->dt), i);
			i = 0;
			node = info->dt;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->mod);
}

/**
 * _setenv - the function
 * @info: the parameter
 * @var: the parameter
 * @value: theparameter
 *  Return: Equal to 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	data_l *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->dt;
	while (node)
	{
		p = init_func(node->rst, var);
		if (p && *p == '=')
		{
			free(node->rst);
			node->rst = buf;
			info->mod = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->dt), buf, 0);
	free(buf);
	info->mod = 1;
	return (0);
}

