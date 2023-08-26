#include "shell.h"

/**
 * add_node - THE FUNCTION
 * @x: the parametre
 * @c:the parameter
 * @m: the parameter
 * Return: there is a return
 */
data_l *add_node(data_l **x, const char *c, int m)
{
	data_l *y;

	if (!x)
		return (NULL);
	y = malloc(sizeof(data_l));
	if (!y)
		return (NULL);
	_memset((void *)y, 0, sizeof(data_l));
	y->runem = m;
	if (c)
	{
		y->rst = _strdup(c);
		if (!y->rst)
		{
			free(y);
			return (NULL);
		}
	}
	y->next = *x;
	*x = y;
	return (y);
}

/**
 * add_node_end - the function
 * @head: the paraleter
 * @str:the parameter
 * @num: the parameter
 *
 * Return: != 0
 */
data_l *add_node_end(data_l **x, const char *c, int m)
{
	data_l *nnds, *nds;

	if (!x)
		return (NULL);

	nds = *x;
	nnds = malloc(sizeof(data_l));
	if (!nnds)
		return (NULL);
	_memset((void *)nnds, 0, sizeof(data_l));
	nnds->runem = m;
	if (c)
	{
		nnds->rst = _strdup(c);
		if (!nnds->rst)
		{
			free(nnds);
			return (NULL);
		}
	}
	if (nds)
	{
		while (nds->next)
			nds = nds->next;
		nds->next = nnds;
	}
	else
		*x = nnds;
	return (nnds);
}

/**
 * print_list_str - the function
 * @h: the parameter
 * Return: ther is a return
 */
size_t print_list_str(const data_l *h)
{
	size_t k = 0;

	while (h)
	{
		_puts(h->rst ? h->rst : "(nil)");
		_puts("\n");
		h = h->next;
		k++;
	}
	return (k);
}

/**
 * nds_dl - the function
 * @x: the function
 * @l: the parameter
 * Return: there is a return
 */
int nds_dl(data_l **x, unsigned int l)
{
	data_l *nds, *nnds;
	unsigned int i = 0;

	if (!x || !*x)
		return (0);

	if (!l)
	{
		nds = *x;
		*x = (*x)->next;
		free(nds->rst);
		free(nds);
		return (1);
	}
	nds = *x;
	while (nds)
	{
		if (i == l)
		{
			nnds->next = nds->next;
			free(nds->rst);
			free(nds);
			return (1);
		}
		i++;
		nnds = nds;
		nds = nds->next;
	}
	return (0);
}

/**
 * free_list - the function
 * @y: the parameter
 * Return:there is a return
 */
void free_list(data_l **y)
{
	data_l *nds, *nnds, *x;

	if (!y || !*y)
		return;
	x = *y;
	nds = x;
	while (nds)
	{
		nnds = nds->next;
		free(nds->rst);
		free(nds);
		nds = nnds;
	}
	*y = NULL;
}

