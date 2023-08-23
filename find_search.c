#include "shell.h"
/**
 * abd – the function
 * @search: the parameter
 * @find: the parameter
 * Return: there is a return
 */
char *abd(const char *search, const char *find)
{
	while (*find)
		if (*find++ != *search++)
			return (NULL);
	return ((char *)search);
}
