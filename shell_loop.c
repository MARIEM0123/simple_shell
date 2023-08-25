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
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
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
 * find_builtin _ the function
 * @info: the parameter
 * Return: there is a return
 */
int find_builtin(info_t *info)
{
	int i, built_in_ret = -1;
	tab_bnt builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->lnumber++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - the function
 * @info: the parameter
 * Return: void
 */
void find_cmd(info_t *info)
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
		if (!is_delim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->link = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->etat = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - function
 * @info: the parameter
 * Return: void
 */
void fork_cmd(info_t *info)
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
			free_info(info, 1);
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
				print_error(info, "Permission denied\n");
		}
	}
}

