#include "shell.h"

/**
 **_strrcpy - the function
 *@P1: the parameter
 *@P2: the parameter
 *@M: the parameter
 *Return: there is a return
 */
char *_strrcpy(char *P1, char *P2, int M)
{
	int k, l;
	char *c = P1;

	k = 0;
	while (P2[k] != '\0' && k < M - 1)
	{
		P1[k] = P2[k];
		k++;
	}
	if (k < M)
	{
		l = k;
		while (l < M)
		{
			P1[l] = '\0';
			l++;
		}
	}
	return (c);
}

/**
 **hr_str - the function
 *@str: the parameter
 *@c: the parameter
 *Return: != 0
 */
char *hr_str(char *str, char c)
{
        do {
                if (*str == c)
                        return (str);
        } while (*str++ != '\0');

        return (NULL);
}
/**
 **_strrcat - the function
 *@P1: the parameter
 *@P2: the parameter
 *@M: the parameter
 *Return: there is a return
 */
char *_strrcat(char *P1, char *P2, int M)
{
	int k, l;
	char *c = P1;

	k = 0;
	l = 0;
	while (P1[k] != '\0')
		k++;
	while (P2[l] != '\0' && l < M)
	{
		P1[k] = P2[l];
		k++;
		l++;
	}
	if (l < M)
		P1[k] = '\0';
	return (c);
}

