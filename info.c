#include "shell.h"

/**
 * clear_info - the function
 * @data: the parameter
 */
void clear_info(info_t *data)
{
	data->arg = NULL;
	data->argv = NULL;
	data->link = NULL;
	data->argc = 0;
}
/**
 * data_lib - the function
 * @data:the parameter
 * @x: there is a return
 */
void data_lib(info_t *data, int x)
{
        lib_f(data->argv);
        data->argv = NULL;
        data->link = NULL;
        if (x)
        {
                if (!data->arr_cmd)
                        free(data->arg);
                if (data->dt)
                        free_list(&(data->dt));
                if (data->sth)
                        free_list(&(data->sth));
                if (data->alias)
                        free_list(&(data->alias));
                lib_f(data->prb);
                        data->prb = NULL;
                lib_g((void **)data->arr_cmd);
                if (data->file_rd > 2)
                        close(data->file_rd);
                _putchar(BUF_FLUSH);
        }
}
/**
 * set_info - the function
 * @data: the parameter
 * @b: the parameter
 */
void set_info(info_t *data, char **b)
{
	int i = 0;

	data->nfd = b[0];
	if (data->arg)
	{
		data->argv = t_str(data->arg, " \t");
		if (!data->argv)
		{
			data->argv = malloc(sizeof(char *) * 2);
			if (data->argv)
			{
				data->argv[0] = _strdup(data->arg);
				data->argv[1] = NULL;
			}
		}
		for (i = 0; data->argv && data->argv[i]; i++)
			;
		data->argc = i;

		alias_md(data);
		vars_md(data);
	}
}

