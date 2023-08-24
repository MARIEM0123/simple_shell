#include "shell.h"
/**
 * don_p_story – the function
 * @DATA: the parameter
 * Return: there is a return
 */
int don_p_story(DATA_t *DATA)
{
	STRRUCT_L *nds = DATA->p_story;
	int i = 0;

	while (nds)
	{
		nds->num = i++;
		nds = nds->too;
	}
	return (DATA->histkk = i);
}

