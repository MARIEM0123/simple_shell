#include "shell.h"

/**
 * _myhistory - the function
 * @info: the parameter
 *  Return:equal to 0
 */
int _myhistory(info_t *info)
{
	print_list(info->sth);
	return (0);
}

/**
 * unset_alias - the function
 * @info: the parameter
 * @str: the sparameter
 * Return: ther is a return
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - the function
 * @info: the parameter
 * @str: the parameter
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - the function
 * @node: the parameter
 * Return: equal to 0
 */
int print_alias(data_l *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->rst, '=');
		for (a = node->rst; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - The function
 * @info: the parameter
 *  Return: equal to 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	data_l *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
 
