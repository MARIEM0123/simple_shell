#include "shell.h"

/**
 * _strlen - the function
 * @s: the parameter
 * Return: the return is != 0
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - the function
 * @s1: the parameter one
 * @s2: the parameter
 * Return: there is a return
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * init_func - the function
 * @haystack: the parameter
 * @needle: the parameter
 * Return: there is a return
 */
char *init_func(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - the function
 * @dest: the parameter
 * @src: the parameter
 * Return: there is a return
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

