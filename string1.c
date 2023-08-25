#include "shell.h"
/**
 * _strcpy – the function
 * @par1: the parameter
 * @par2: the parameter
 * Return: there is a return
 */
char *_strcpy(char *par1, char *par2)
{
        int i = 0;

        if (par1 == par2 || par2 == 0)
                return (par1);
        while (par2[i])
        {
                par1[i] = par2[i];
                i++;
        }
        par1[i] = 0;
        return (par1);
}
/**
 * _strdup – the function
 * @c: paraeter
 *
 * Return: there is a return
 */
char *_strdup(const char *c)
{
        int x = 0;
        char *y;

        if (c == NULL)
                return (NULL);
        while (*c++)
                x++;
        y = malloc(sizeof(char) * (x + 1));
        if (!y)
                return (NULL);
        for (x++; x--;)
                y[x] = *--c;
        return (y);
}
/**
 * _puts - the function to print a string
 * @str: the string to print
 */
void _puts(char *str)
{
        while (*str != '\0')
        {
                _putchar(*str);
                str++;
        }
        _putchar ('\n');
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}
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
                while (the_delimiter(c[i], d))
                        i++;
                k = 0;
                while (!the_delimiter(c[i + k], d) && c[i + k])
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

