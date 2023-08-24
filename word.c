#include "shell.h"

/**
 * **word_str – the function
 * @c: the parameter
 * @d: the parameter
 * Return: there is a return != null
 */

char **word_str(char *c, char *d)
{
	int i, j, k, l, count= 0;
	char **s;

	if (c == NULL || c[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; c[i] != '\0'; i++)
		if (!the_delimiter(c[i], d) && (the_delimiter(c[i + 1], d) || !c[i + 1]))
			count++;

	if (count == 0)
		return (NULL);
	s = malloc((1 + count) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < count; j++)
	{
		while (the_delimiter(str[i], d))
			i++;
		k = 0;
		while (!the_delimiter(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (l = 0; l < k; l++)
			s[j][l] = c[i++];
		s[j][l] = 0;
	}
	s[j] = NULL;
	return (s);
}

