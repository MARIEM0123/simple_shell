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
/**
 * rw_p_story – the function
 * @DATA: the parameter
 * Return: there is a return
 */
int rw_p_story(DATA_t *DATA)
{
	ssize_t ffile;
	char *filepnn = ret_story_fd(DATA);
	STRRUCT_L *nds = NULL;

	if (!filepnn)
		return (-1);

	ffile = open(filepnn, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filepnn);
	if (ffile == -1)
		return (-1);
	for (nds = DATA->p_story; nds; nds = nds->too)
	{
		_putsffile(nds->str, ffile);
		_putffile('\n', ffile);
	}
	_putffile(MIINUSONE, ffile);
	close(ffile);
	return (1);
}

