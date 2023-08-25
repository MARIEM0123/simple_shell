#include "shell.h"
/**
 * _getenv - the function to be determinated in here
 * @data:the parameter to be defined
 * @name: paraeter
 * Return:!= 0
 */
char *_getenv(info_t *data, const char *m)
{
        data_l *nds = data->dt;
        char *p;

        while (nds)
        {
                p = init_func(nds->rst, m);
                if (p && *p)
                        return (p);
                nds = nds->next;
        }
        return (NULL);
}
/**
 * _myenv - the function to be defined in here
 * @data: the parameter to be defined
 * Return: equal to 0
i */
int _myenv(info_t *data)
{
	print_list_str(data->dt);
	return (0);
}

/**
 * _mysetenv - The function to be defined in here
 * @info: the parameter to be determineted
 *  Return: Equal to 0
 */
int _mysetenv(info_t *data)
{
	if (data->argc != 3)
	{
		_eputs("Error message\n");
		return (1);
	}
	if (_setenv(data, data->argv[1], data->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - the function to be defined in here
 * @info: the parameter to be determinated
 * Return: Equal to 0
 */
int _myunsetenv(info_t *data)
{
	int i;

	if (data->argc == 1)
	{
		_eputs("Error message");
		return (1);
	}
	for (i = 1; i <= data->argc; i++)
		_unsetenv(data, data->argv[i]);

	return (0);
}

/**
 * list_env_p - the function to be defined in here 
 * @info: the parameter to be determinated
 * Return: Equal to 0
 */
int list_env_p(info_t *data)
{
	data_l *nds = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&nds, environ[i], 0);
	data->dt = nds;
	return (0);
}

