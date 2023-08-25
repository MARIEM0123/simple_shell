#include "shell.h"

/**
 * hsh - the function
 * @data: the parameter
 * @b: the parameter
 * Return: there is a return
 */
int hsh(info_t *data, char **b)
{
	ssize_t r = 0;
	int x = 0;

	while (r != -1 && x != -2)
	{
		clear_info(data);
		if (interactive(data))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(data);
		if (r != -1)
		{
			set_info(data, b);
			x = find_builtin(data);
			if (x == -1)
				find_cmd(data);
		}
		else if (interactive(data))
			_putchar('\n');
		data_lib(data, 0);
	}
	write_history(data);
	data_lib(data, 1);
	if (!interactive(data) && data->etat)
		exit(data->etat);
	if (x == -2)
	{
		if (data->n_er == -1)
			exit(data->etat);
		exit(data->n_er);
	}
	return (x);
}

/**
 * find_builtin - the function
 * @data: the parameter
 * Return: there is a return
 */
int find_builtin(info_t *data)
{
	int i, x = -1;
	tab_bnt y[] = {
		{"exit", exit_func},
		{"env", _myenv},
		{"help", func_hp},
		{"history", _hstr},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _cd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; y[i].es; i++)
		if (_strcmp(data->argv[0], y[i].es) == 0)
		{
			data->lnumber++;
			x = y[i].gc(data);
			break;
		}
	return (x);
}

/**
 * find_cmd - the function
 * @info: the parameter
 * Return: void
 */
void find_cmd(info_t *data)
{
	char *link = NULL;
	int i, k;

	data->link = data->argv[0];
	if (data->numbers == 1)
	{
		data->lnumber++;
		data->numbers = 0;
	}
	for (i = 0, k = 0; data->arg[i]; i++)
		if (!delimiter(data->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	link = find_path(data, _getenv(data, "PATH="), data->argv[0]);
	if (link)
	{
		data->link = link;
		fork_cmd(data);
	}
	else
	{
		if ((interactive(data) || _getenv(data, "PATH=")
					|| data->argv[0][0] == '/') && is_cmd(data, data->argv[0]))
			fork_cmd(data);
		else if (*(data->arg) != '\n')
		{
			data->etat = 127;
			err_output(data, "Error messaor no such path\n");
		}
	}
}

/**
 * fork_cmd - function
 * @data: the parameter
 * Return: void
 */
void fork_cmd(info_t *data)
{
	pid_t cd;

	cd = fork();
	if (cd == -1)
	{
		perror("there is an error:");
		return;
	}
	if (cd == 0)
	{
		if (execve(data->link, data->argv, get_environ(data)) == -1)
		{
			data_lib(data, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(data->etat));
		if (WIFEXITED(data->etat))
		{
			data->etat = WEXITSTATUS(data->etat);
			if (data->etat == 126)
				err_output(data, "Error message no access\n");
		}
	}
}

