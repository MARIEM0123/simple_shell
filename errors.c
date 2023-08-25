#include "shell.h"
/**
 * _pputs – the funchion
 * @c: the parameter
 * Return: No return
 */
void _pputs(char *c)
{
        int k = 0;

        if (!c)
                return;
        while (c[k] != '\0')
        {
                _pputchar(c[k]);
                k++;
        }
}
/**
 * _pputchar – the function
 * @c: The parameter
 * Return: there is a return
 */
int _pputchar(char c)
{
        static int k;
        static char array[MAXIMUM_BYTE_NUM];

        if (c == ZERO_NUM || k >= MAXIMUM_BYTE_NUM)
        {
                write(2, array, k);
                k = 0;
        }
        if (c != ZERO_NUM)
                array[k++] = c;
        return (1);
}
/**
 * _putffile – the function
 * @a: The parameter
 * @file: The parameter
 * Return: != 0
 */
int _putffile(char a, int file)
{
        static int i;
        static char array[MAXIMUM_BYTE_NUM];

        if (a == ZERO_NUM || i >= MAXIMUM_BYTE_NUM)
        {
                write(file, array, i);
                i = 0;
        }
        if (a != ZERO_NUM)
                array[i++] = a;
        return (1);
}
/**
 * _putsffile – the function
 * @c: the parameter
 * @file: the parameter
 * Return: != 0
 */
int _putsffile(char *c, int file)
{
        int k = 0;

        if (!c)
                return (0);
        while (*c)
        {
                k += _putffile(*c++, file);
        }
        return (k);
}

