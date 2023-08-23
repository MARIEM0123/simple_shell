#include "shell.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * input_array – the function
 * @DATA: the input data
 * @array: the array 
 * @l: the parameter
 * Return: the is a return different th 0
 */
ssize_t input_array(DATA_t *DATA, char **array, size_t*l)
{
	ssize_t x = 0;
	size_t hau = 0;

	if (!*l)
	{
		free(*array);
		*array = NULL;
		signal(SIGINT, handle_var);
#if USE_LINE_PARM
		x = line_parm(array, &hau, stdin);
#else
		x = _line_parm(DATA, array, &hau);
#endif
		if (x > 0)
		{
			if ((*array)[x - 1] == '\n')
			{
				(*array)[x - 1] = '\0';
				x--;
			}
			DATA->linekk_flag = 1;
			rm_ct(*array);
			h_his(DATA, *array, DATA->histkk++);
			{
				*l = x;
				DATA->L_array = array;
			}
		}
	}
	return (x);
}

/**
 * rm_ct – the function
 * @array: the parameter
 * Return: null
 */
void rm_ct(char *array)
{
	int x;

	for (x = 0; array[x] != '\0'; x++)
		if (array[x] == '#' && (!x || array[x - 1] == ' '))
		{
			array[x] = '\0';
			break;
		}
}

