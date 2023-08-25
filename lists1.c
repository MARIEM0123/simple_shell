#include "shell.h"

/**
 * list_len - THE function
 * @h: parameter
 * Return: there is a return
 */
size_t list_len(const data_l *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - the function
 * @head: the parameter
 * Return: there is a return
 */
char **list_to_strings(data_l *head)
{
	data_l *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->rst) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->rst);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * print_list - the function
 * @h: the parameter
 * Return: there is a return
 */
size_t print_list(const data_l *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(n_conv(h->runem, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->rst ? h->rst : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - the function
 * @node: the parameter
 * @prefix: the parameter
 * @c: the parameter
 * Return: !=0
 */
data_l *node_starts_with(data_l *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = init_func(node->rst, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index -the function
 * @head: the parameter
 * @node: the parameter
 * Return: the return is != 0
 */
ssize_t get_node_index(data_l *head, data_l *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

