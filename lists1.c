#include "shell.h"
/**
 * get_node_index -the function
 * @x: the parameter
 * @nds: the parameter
 * Return: the return is != 0
 */
ssize_t get_node_index(data_l *x, data_l *nds)
{
        size_t i = 0;

        while (x)
        {
                if (x == nds)
                        return (i);
                x = x->next;
                i++;
        }
        return (-1);
}
/**
 * list_len - THE function
 * @x: parameter
 * Return: there is a return
 */
size_t list_len(const data_l *x)
{
	size_t i = 0;

	while (x)
	{
		x = x->next;
		i++;
	}
	return (i);
}

/**
 * strings_list - the function
 * @x: the parameter
 * Return: there is a return
 */
char **strings_list(data_l *x)
{
	data_l *nds = x;
	size_t i = list_len(x), j;
	char **y;
	char *str;

	if (!x || !i)
		return (NULL);
	y = malloc(sizeof(char *) * (i + 1));
	if (!y)
		return (NULL);
	for (i = 0; nds; nds = nds->next, i++)
	{
		str = malloc(_strlen(nds->rst) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(y[j]);
			free(y);
			return (NULL);
		}

		str = _strcpy(str, nds->rst);
		y[i] = str;
	}
	y[i] = NULL;
	return (y);
}


/**
 * node_starts_with - the function
 * @nds: the parameter
 * @f: the parameter
 * @c: the parameter
 * Return: !=0
 */
data_l *node_starts_with(data_l *nds, char *f, char c)
{
	char *p = NULL;

	while (nds)
	{
		p = init_func(nds->rst, f);
		if (p && ((c == -1) || (*p == c)))
			return (nds);
		nds = nds->next;
	}
	return (NULL);
}
/**
 * print_list - the function
 * @h: the parameter
 * Return: there is a return
 */
size_t print_list(const data_l *x)
{
        size_t i = 0;

        while (x)
        {
                _puts(n_conv(x->runem, 10, 0));
                _putchar(':');
                _putchar(' ');
                _puts(x->rst ? x->rst : "(nil)");
                _puts("\n");
                x = x->next;
                i++;
        }
        return (i);
}
