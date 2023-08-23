#include "shell.h"
/**
 **_strchr – the function,
 *@str: the sparameter
 *@x: theparameter
 *Return: there is a return !=NULL
 */
char *_strchr(char *str, char x)
{
	do {
		if (*str == x)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}

