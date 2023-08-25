#include "shell.h"


/**
 * lib_f - the function
 * @x: the parameter
 */
void lib_f(char **x)
{
	char **i = x;

	if (!x)
		return;
	while (*x)
		free(*x++);
	free(i);
}

/**
 * _realloc  thefunction
 * @ss: the parameter
 * @P1: parameter
 * @P2:the parameter
 * Return: there is a return
 */
void *_realloc(void *ss, unsigned int P1, unsigned int P2)
{
	char *p;

	if (!ss)
		return (malloc(P2));
	if (!P2)
		return (free(ss), NULL);
	if (P2 == P1)
		return (ss);

	p = malloc(P2);
	if (!p)
		return (NULL);

	P1 = P1 < P2 ? P1 : P2;
	while (P1--)
		p[P1] = ((char *)ss)[P1];
	free(ss);
	return (p);
}
/**
 * _memset -the function
 * @str: the parameter
 * @a: the parrameter
 * @n: the parameter
 * Return: there is a return
 */
char *_memset(char *str, char a, unsigned int n)
{
        unsigned int i;

        for (i = 0; i < n; i++)
                str[i] = a;
        return (str);
}
