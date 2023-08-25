#include "shell.h"

/**
 * get_environ - the function
 * @info: the parameter
 * Return:equal to 0
 */
char **get_environ(info_t *data)
{
	if (!data->prb || data->mod)
	{
		data->prb = list_to_strings(data->dt);
		data->mod = 0;
	}

	return (data->prb);
}


/**
 * _setenv - the function
 * @info: the parameter
 * @var: the parameter
 * @value: theparameter
 *  Return: Equal to 0
 */
int _setenv(info_t *data, char *x, char *y)
{
	char *array = NULL;
	data_l *nds;
	char *p;

	if (!x || !y)
		return (0);

	array = malloc(_strlen(x) + _strlen(y) + 2);
	if (!array)
		return (1);
	_strcpy(array, x);
	_strcat(array, "=");
	_strcat(array, y);
	nds = data->dt;
	while (nds)
	{
		p = init_func(nds->rst, x);
		if (p && *p == '=')
		{
			free(nds->rst);
			nds->rst = array;
			data->mod = 1;
			return (0);
		}
		nds = nds->next;
	}
	add_node_end(&(data->dt), array, 0);
	free(array);
	data->mod = 1;
	return (0);
}

/**
 * _unsetenv - The function
 * @info: the parameter
 *  Return: there is a return
 * @var: the parameter
 */
int _unsetenv(info_t *data, char *x)
{
        data_l *nds = data->dt;
        size_t i = 0;
        char *p;

        if (!nds || !x)
                return (0);

        while (nds)
        {
                p = init_func(nds->rst, x);
                if (p && *p == '=')
                {
                        data->mod= delete_node_at_index(&(data->dt), i);
                        i = 0;
                        nds = data->dt;
                        continue;
                }
                nds = nds->next;
                i++;
        }
        return (data->mod);
}        
