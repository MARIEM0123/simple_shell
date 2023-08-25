#include "shell.h"

/**
 * _myenv - the function
 * @info: the parameter
 * Return: equal to 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->dt);
	return (0);
}

/**
 * _getenv - the function
 * @info:the parameter
 * @name: paraeter
 * Return:!= 0
 */
char *_getenv(info_t *info, const char *name)
{
	data_l *node = info->dt;
	char *p;

	while (node)
	{
		p = init_func(node->rst, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - The function
 * @info: the parameter
 *  Return: Equal to 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Error message\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - the function
 * @info: the parameter
 * Return: Equal to 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Error message");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - the function
 * @info: the parameter
 * Return: Equal to 0
 */
int populate_env_list(info_t *info)
{
	data_l *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->dt = node;
	return (0);
}

