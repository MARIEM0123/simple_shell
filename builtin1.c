#include "shell.h"

/**
 * unset_alias - the function to be defined in here
 * @data: the parameter indicated
 * @ch: the sparameter
 * Return: ther is a return
 */
int unset_alias(info_t *data, char *ch)
{
	char *p, c;
	int x;

	p = hr_str(ch, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	x = delete_node_at_index(&(data->alias),
		get_node_index(data->alias, node_starts_with(data->alias, ch, -1)));
	*p = c;
	return (x);
}

/**
 * set_alias - the function to be defined in her
 * @data: the parameter to be indicated
 * @ch: the parameter
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *data, char *ch)
{
	char *p;

	p = hr_str(ch, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(data, ch));

	unset_alias(data, ch);
	return (add_node_end(&(data->alias), ch, 0) == NULL);
}

/**
 * print_alias - the function to be defined in here
 * @nds: the parameter to be indicated
 * Return: equal to 0
 */
int print_alias(data_l *nds)
{
	char *p = NULL, *a = NULL;

	if (nds)
	{
		p = hr_str(nds->rst, '=');
		for (a = nds->rst; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - The function to be defined in here
 * @data: the parameter to be indicated
 *  Return: equal to 0
 */
int _myalias(info_t *data)
{
	int i = 0;
	char *p = NULL;
	data_l *nds = NULL;
	
	if (data->argc == 1)
	{
		nds = data->alias;
		while (nds)
		{
			print_alias(nds);
			nds = nds->next;
		}
		return (0);
	}
	for (i = 1; data->argv[i]; i++)
	{
		p = hr_str(data->argv[i], '=');
		if (p)
			set_alias(data, data->argv[i]);
		else
			print_alias(node_starts_with(data->alias, data->argv[i], '='));
	}

	return (0);
}
/**
 * _hstr - the function to be defined in here
 * @data: the parameter to be indicated
 *  Return:equal to 0
 */
int _hstr(info_t *data)
{
        print_list(data->sth);
        return (0);
} 
