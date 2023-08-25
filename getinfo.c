#include "shell.h"

/**
 * clear_info - the function
 * @info: the parameter
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->link = NULL;
	info->argc = 0;
}

/**
 * set_info - the function
 * @info: the parameter
 * @av: the parameter
 */
void set_info(info_t *info, char **av)
{
	int i = 0;

	info->nfd = av[0];
	if (info->arg)
	{
		info->argv = t_str(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * data_lib - the function
 * @info:the parameter
 * @all: there is a return
 */
void data_lib(info_t *info, int all)
{
	lib_f(info->argv);
	info->argv = NULL;
	info->link = NULL;
	if (all)
	{
		if (!info->arr_cmd)
			free(info->arg);
		if (info->dt)
			free_list(&(info->dt));
		if (info->sth)
			free_list(&(info->sth));
		if (info->alias)
			free_list(&(info->alias));
		lib_f(info->prb);
			info->prb = NULL;
		lib_g((void **)info->arr_cmd);
		if (info->file_rd > 2)
			close(info->file_rd);
		_putchar(BUF_FLUSH);
	}
}

