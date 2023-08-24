#include "shell.h"

/**
 * data_net – the function
 * @DATA: the parameter
 */
void data_net(DATA_t *DATA)
{
	DATA->arg = NULL;
	DATA->argv = NULL;
	DATA->path = NULL;
	DATA->argc = 0;
}


/**
 * mode_intr – the function
 * @DATA: the parameter
 * Return: there is a return
 */
int mode_intr(DATA_t *DATA)
{
	return (isatty(STDIN_FILENO) && DATA->rddfile <= 2);
}
/**
 * p_input_line – operation on the lines
 * @DATA: the structure given
 * Return: is different that NULL
 */
ssize_t p_input_line(DATA_t *DATA)
{
	static char *array;
	static size_t i, j, l;
	ssize_t x = 0;
	char **array_p = &(DATA->arg), *p;

	_putchar(MIINUSONE);
	x = input_array(DATA, &array, &l);
	if (x == -1)
		return (-1);
	if (l)
	{
		j = i;
		p = array + i;

		VERIFIC(DATA, array, &j, i, l);
		while (j < l) 
		{
			if (VRFC(DATA, array, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= l)
		{
			i = l = 0;
			DATA->L_array_type = ZERO_NUM;
		}

		*array_p = p;
		return (stline(p));
	}

	*array_p = array;
	return (x);
}

/**
 * DATA_star – the function
 * @DATA: th aparameter
 * @b: the parameter
 */
void DATA_star(DATA_t *DATA, char **b)
{
	int k = 0;

	DATA->fpnn = b[0];
	if (DATA->arg)
	{
		DATA->argv = word_str(DATA->arg, " \t");
		if (!DATA->argv)
		{
			DATA->argv = malloc(sizeof(char *) * 2);
			if (DATA->argv)
			{
				DATA->argv[0] = _strdup(DATA->arg);
				DATA->argv[1] = NULL;
			}
		}
		for (k = 0; DATA->argv && DATA->argv[k]; k++)
			;
		DATA->argc = k;

		alias_subt(DATA);
		varias_subt(DATA);
	}
}

