#include "shell.h"
/**
 * _len_string – the function
 * @c: the parameter
 * Return: there is a return
 */
int _len_string(char *c)
{
        int k = 0;
        if (!c)
                return (0);

        while (*c++)
                k++;
        return (k);
}
/**
 * _strcompare  - the function
 * @c1: the parameter one
 * @c2: the parameter two
 *
 * Return: != 0
 */
int _strcompare (char *c1, char *c2)
{
        while (*c1 && *c2)
        {
                if (*c1 != *c2)
                        return (*c1 - *c2);
                c1++;
                c2++;
        }
        if (*c1 == *c2)
                return (0);
        else
                return (*c1 < *c2 ? -1 : 1);
}
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
/**
 * _strcat -  the function
 * @par1: the parameter
 * @par2: the parameter
 * Return: !=0
 */
char *_strcat(char *par1, char *par2)
{
        char *x = par1;

        while (*par1)
                par1++;
        while (*par2)
                *par1++ = *par2++;
        *par1 = *par2;
        return (x);
}

