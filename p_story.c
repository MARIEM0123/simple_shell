#include "shell.h"
#include <stddef.h>
STRRUCT_L *add_nds_end(STRRUCT_L **h, const char *ch, int num);
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
	add_nds_z(&nds, array, linekk);

	if (!DATA->p_story)
		DATA->p_story = nds;
	return (0);
}
/**
 * _ myp_story – the function
 * @DATA: parametr
 *  Return: equal to 0
 */
int _myp_story(DATA_t *DATA)
{
	p_strings(DATA-> p_story);
	return (0);
}

