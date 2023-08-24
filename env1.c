#include "shell.h"
/**
 * NW_ennv – the function
 * @DATA: the parameter
 * Return: is equal to 0
 */
int NW_ennv(DATA_t *DATA)
{
	p_strings(DATA->evn);
	return (0);
}
/**
 * p_strings – the function
 * @p: the parameter
 * Return: ther is a return
 */
size_t p_strings(const STRRUCT_L *p)
{
	size_t k = 0;

	while (p)
	{
		_puts(p->str ? p->str : "(nil)");
		_puts("\n");
		p = p->too;
		k++;
	}
	return (k);
}
/**
 * ch_dir – the function
 * @DATA: the parameter
 * Return: equal to 0
 */
int ch_dir(DATA_t *DATA)
{
	char **array;

	array = DATA->argv;
	_puts("Error message \n");
	if (0)
		_puts(*array);
	return (0);
}

