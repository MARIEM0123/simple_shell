#include "shell.h"

/**
 * exit_func - the function
 * @info: the parameter
 * Return: there is a return
 */
int exit_func(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = _atoi2(info->argv[1]);
		if (exitcheck == -1)
		{
			info->etat = 2;
			err_output(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->n_er = _atoi2(info->argv[1]);
		return (-2);
	}
	info->n_er = -1;
	return (-2);
}

/**
 * _cd - the function
 * @info: the parameter
 * Return:equal to 0
 */
int _cd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("Error message<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		err_output(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * func_hp - the function
 * @info: the parameter
 * Return: equal to 0
 */
int func_hp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("Error message \n");
	if (0)
		_puts(*arg_array);
	return (0);
}

