#include "shell.h"
/**
 * init_func - the function
 * @s: the parameter
 * @c: the parameter
 * Return: there is a return
 */
char *init_func(const char *s, const char *c)
{
        while (*c)
                if (*c++ != *s++)
                        return (NULL);
        return ((char *)s);
}

/**
 * _strlen - the function
 * @str: the parameter
 * Return: the return is != 0
 */
int _strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (*str++)
		i++;
	return (i);
}

/**
 * _strcmp - the function
 * @str1: the parameter one
 * @str2: the parameter
 * Return: there is a return
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * _strcat - the function
 * @P1: the parameter
 * @P2: the parameter
 * Return: there is a return
 */
char *_strcat(char *P1, char *P2)
{
	char *P2 = P1;

	while (*P1)
		P1++;
	while (*P2)
		*P1++ = *P2++;
	*P1 = *P2;
	return (P2);
}

