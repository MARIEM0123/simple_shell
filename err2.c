#include "shell.h"
/**
 * error_output – the function
 * @DATA: the data to input
 * @c: parameter
 * Return: the is a return
 */
void error_output(DATA_t *DATA, char *c)
{
	_entry(DATA->fpnn);
	_entry(": ");
	p_dtt(DATA->num_lines, STDERR_FILENO);
	_entry(": ");
	_entry(DATA->argv[0]);
	_entry(": ");
	_entry(c);
}

