#include "shell.h"
/**
 * hloop - function
 * @DATA: the parameter
 * @b: the parameter
 * Return: there is a return
 */
int hloop(DATA_t *DATA, char **b)
{
	ssize_t x = 0;
	int a = 0;

	while (x != -1 && a != -2)
	{
		data_net (DATA);
		if (mode_intr(DATA))
			_puts("$ ");
		_pprtchar(MIINUSONE);
		x = p_input_line(DATA);
		if (x != -1)
		{
			set_DATA(DATA, b);
			a = find_builtin(DATA);
			if (a == -1)
				find_cmd(DATA);
		}
		else if (mode_intr(DATA))
			_putchar('\n');
		free_DATA(DATA, 0);
	}
	rw_p_story(DATA);
	free_DATA(DATA, 1);
	if (!mode_intr(DATA) && DATA->etat)
		exit(DATA->etat);
	if (a == -2)
	{
		if (DATA->increm == -1)
			exit(DATA->etat);
		exit(DATA->increm);
	}
	return (a);
}

