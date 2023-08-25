#include "shell.h"

/**
 * func_hp - the function
 * @data: the parameter
 * Return: equal to 0
 */
int func_hp(info_t *data)
{
        char **arr;

        arr = data->argv;
        _puts("Error message \n");
        if (0)
                _puts(*arr);
        return (0);
}


/**
 * _cd - the function
 * @data: the parameter
 * Return:equal to 0
 */
int _cd(info_t *data)
{
	char *c, *x, array[1024];
	int y;

	c = getcwd(array, 1024);
	if (!c)
		_puts("Error\n");
	if (!data->argv[1])
	{
		x = _getenv(data, "HOME=");
		if (!x)
			y = chdir((x = _getenv(data, "PWD=")) ? x : "/");
		else
			y = chdir(x);
	}
	else if (_strcmp(data->argv[1], "-") == 0)
	{
		if (!_getenv(data, "OLDPWD="))
		{
			_puts(c);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(data, "OLDPWD=")), _putchar('\n');
		y = chdir((x = _getenv(data, "OLDPWD=")) ? x : "/");
	}
	else
		y = chdir(data->argv[1]);
	if (y == -1)
	{
		err_output(data, "Error message no access ");
		_eputs(data->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(data, "OLDPWD", _getenv(data, "PWD="));
		_setenv(data, "PWD", getcwd(array, 1024));
	}
	return (0);
}
/**
 * exit_func - the function
 * @data: the parameter
 * Return: there is a return
 */
int exit_func(info_t *data)
{
        int x;

        if (data->argv[1])
        {
                x = _atoi2(data->argv[1]);
                if (x == -1)
                {
                        data->etat = 2;
                        err_output(data, "IError message: ");
                        _eputs(data->argv[1]);
                        _eputchar('\n');
                        return (1);
                }
                data->n_er = _atoi2(data->argv[1]);
                return (-2);
        }
        data->n_er = -1;
        return (-2);
}
