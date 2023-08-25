#include "shell.h"
/**
 **_strncpy – the function
 *@par1: the parameter 1
 *@par2: theparameter 2
 *@count: number of characters
 *Return: the new parameter
 */
char *_strncpy(char *par1, char *par2, int count)
{
        int a, b;
        char *str = par1;
        a = 0;
        while (par2[a] != '\0' && a < count - 1)
        {
                par1[a] = par2[a];
                a++;
        }
        if (a < count)
        {
                b = a;
                while (b < count)
                {
                        par1[b] = '\0';
                        b++;
                }
        }
        return (str);
}
/**
 **_strncat – the function
 *@par1: the parameter1
 *@par2: the parameter2
 *@count: the parameter
 *Return: the concatenated string
 */
char *_strncat(char *par1, char *par2, int count)
{
        int a, b;
        char *str = par1;

        a = 0;
        b = 0;
        while (par1[a] != '\0')
                a++;
        while (par2[b] != '\0' && b < count)
        {
                par1[a] = par2[b];
                a++;
                b++;
        }
        if (b < count)
                par1[a] = '\0';
        return (str);
}
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

