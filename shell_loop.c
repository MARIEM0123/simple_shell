#include "shell.h"

/**
 * hsh - the function
 * @info: the parameter
 * @av: the parameter
 * Return: there is a return
 */
int hsh(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			builtin_ret = blt_fnd(info);
			if (builtin_ret == -1)
				cmd_fnd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		data_lib(info, 0);
	}
	write_history(info);
	data_lib(info, 1);
	if (!interactive(info) && info->etat)
		exit(info->etat);
	if (builtin_ret == -2)
	{
		if (info->n_er == -1)
			exit(info->etat);
		exit(info->n_er);
	}
	return (builtin_ret);
}

/**
 * blt_fnd - the function
 * @info: the parameter
 * Return: there is a return
 */
int blt_fnd(info_t *info)
{
	int i, built_in_ret = -1;
	tab_bnt builtintbl[] = {
		{"exit", exit_func},
		{"env", _myenv},
		{"help", func_hp},
		{"history", _hstr},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _cd},
		{"alias", _alias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].es; i++)
		if (_strcmp(info->argv[0], builtintbl[i].es) == 0)
		{
			info->lnumber++;
			built_in_ret = builtintbl[i].gc(info);
			break;
		}
	return (built_in_ret);
}

/**
 * cmd_fnd - the function
 * @info: the parameter
 * Return: void
 */
void cmd_fnd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->link = info->argv[0];
	if (info->numbers == 1)
	{
		info->lnumber++;
		info->numbers = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!delimiter(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = path_fnd(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->link = path;
		cmd_K(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && cmd_check(info, info->argv[0]))
			cmd_K(info);
		else if (*(info->arg) != '\n')
		{
			info->etat = 127;
			err_output(info, "not found\n");
		}
	}
}

/**
 * cmd_K - function
 * @info: the parameter
 * Return: void
 */
void cmd_K(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error message:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->link, info->argv, get_environ(info)) == -1)
		{
			data_lib(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->etat));
		if (WIFEXITED(info->etat))
		{
			info->etat = WEXITSTATUS(info->etat);
			if (info->etat == 126)
				err_output(info, "Permission denied\n");
		}
	}
}

