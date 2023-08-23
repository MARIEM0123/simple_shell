#include "shell.h"
/**
 * VERIFIC – the function
 * @DATA: the parameter
 * @array: the array
 * @x: the parameter pointer
 * @c: the first case
 * @ll: the parameter
 * Return: there is a return
 */
void VERIFIC(DATA_t *DATA, char *array, size_t*x, size_t c, size_t ll)
{
	size_t k = *x;

	if (DATA->L_array_type == NUM_TWO)
	{
		if (DATA->etat)
		{
			array[c] = 0;
			k = ll;
		}
	}
	if (DATA->L_array_type == NUM_UN)
	{
		if (!DATA->etat)
		{
			array[c] = 0;
			k = ll;
		}
	}

	*x = k;
}

