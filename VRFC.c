#include "shell.h"

/**
 * VRFC – the function
 * @data: the parameter
 * @array: tha patrameter type array
 * @x: pointer
 * Return: there is a return
 */
int VRFC(DATA_t *DATA, char *array, size_t *x)
{
	size_t k = *x;

	if (array[k] == '|' && array[k + 1] == '|')
	{
		array[k] = 0;
		k++;
		DATA-> L_array_type = NUM_UN;
	}
	else if (array[k] == '&' && array[k + 1] == '&')
	{
		array[k] = 0;
		k++;
		DATA-> L_array_type = NUM_TWO	;
	}
	else if (array[k] == ';')
	{
		array[k] = 0;
		DATA-> L_array_type = NUM_TREE;
	}
	else
		return (0);
	*x = k;
	return (1);
}

