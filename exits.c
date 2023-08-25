#include "shell.h"

/**
 **_strrcpy - the function
 *@dest: the parameter
 *@src: the parameter
 *@n: the parameter
 *Return: there is a return
 */
char *_strrcpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strrcat - the function
 *@dest: the parameter
 *@src: the parameter
 *@n: the parameter
 *Return: there is a return
 */
char *_strrcat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **hr_str - the function
 *@s: the parameter
 *@c: the parameter
 *Return: != 0
 */
char *hr_str(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

