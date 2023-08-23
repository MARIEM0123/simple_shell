#include "shell.h"
#include <stddef.h>
/**
 * h_his – the function
 * @DATA: the parameter
 * @array: the array parameter
 * @linekk: parameter
 * Return: is equal to 0
 */
int h_his(DATA_t *DATA, char *array, int linekk)
{
	STRRUCT_L *nds = NULL;

	if (DATA->p_story)
		nds = DATA->p_story;
	add_nds_end(&nds, array, linekk);

	if (!DATA->p_story)
		DATA->p_story = nds;
	return (0);
}

