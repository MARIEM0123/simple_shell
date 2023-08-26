#include "shell.h"

/**
 * **strtow - the function
 * @c: the parameter
 * @x: the parameter
 * Return: the parameter
 */

char **t_str(char *c, char *x)
{
        int i, j, k, m, y = 0;
        char **s;

        if (c == NULL || c[0] == 0)
                return (NULL);
        if (!x)
                x = " ";
        for (i = 0; c[i] != '\0'; i++)
                if (!delimiter(c[i], x) && (delimiter(c[i + 1], x) || !c[i + 1]))
                        y++;

        if (y == 0)
                return (NULL);
        s = malloc((1 + y) * sizeof(char *));
        if (!s)
                return (NULL);
        for (i = 0, j = 0; j < y; j++)
        {
                while (delimiter(c[i], x))
                        i++;
                k = 0;
                while (!delimiter(c[i + k], x) && c[i + k])
                        k++;
                s[j] = malloc((k + 1) * sizeof(char));
                if (!s[j])
                {
                        for (k = 0; k < j; k++)
                                free(s[k]);
                        free(s);
                        return (NULL);
                }
                for (m = 0; m < k; m++)
                        s[j][m] = c[i++];
                s[j][m] = 0;
        }
        s[j] = NULL;
        return (s);
}

/**
 * **t2_str - the function
 * @c: the parameter
 * @x: the parameter
 * Return: there is a return
 */
char **t2_str(char *c, char x)
{
        int i, j, k, a, y = 0;
        char **s;

        if (c == NULL || c[0] == 0)
                return (NULL);
        for (i = 0; c[i] != '\0'; i++)
                if ((c[i] != x && c[i + 1] == x) ||
                                    (c[i] != x && !c[i + 1]) || c[i + 1] == x)
                        y++;
        if (y == 0)
                return (NULL);
        s = malloc((1 + y) * sizeof(char *));
        if (!s)
                return (NULL);
        for (i = 0, j = 0; j < y; j++)
        {
                while (c[i] == x && c[i] != x)
                        i++;
                k = 0;
                while (c[i + k] != x && c[i + k] && c[i + k] != x)
                        k++;
                s[j] = malloc((k + 1) * sizeof(char));
                if (!s[j])
                {
                        for (k = 0; k < j; k++)
                                free(s[k]);
                        free(s);
                        return (NULL);
                }
                for (a = 0; a < k; a++)
                        s[j][a] = c[i++];
                s[j][a] = 0;
        }
        s[j] = NULL;
        return (s);
}

