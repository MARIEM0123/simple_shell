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
/**
 * lib_DATA – the function
 * @DATA: parameter
 * @fld: the parameter
 */
void lib_DATA(DATA_t *DATA, int fld)
{
	str_free(DATA->argv);
	DATA->argv = NULL;
	DATA->path = NULL;
	if (fld)
	{
		if (!DATA->L_array)
			free(DATA->arg);
		if (DATA->evn)
			lib_data(&(DATA->evn));
		if (DATA->p_story)
			lib_data(&(DATA->p_story));
		if (DATA->alias)
			lib_data(&(DATA->alias));
		str_free(DATA->par_envv);
			DATA->par_envv = NULL;
		lib_pointer((void **)DATA->L_array);
		if (DATA->rddfile > 2)
			close(DATA->rddfile);
		_putchar(MIINUSONE);
	}
}

