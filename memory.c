#include "shell.h"

/**
 * bfree - the function
 * @ptr: the parameter
 * Return:vthere is a return
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

