#include "shell.h"
/**
 * lib_pointer – the function
 * @x: parameter
 * Return: ther is a return
 */
int lib_pointer(void **x)
{
        if (x && *x)
        {
                free(*x);
                *x = NULL;
                return (1);
        }
        return (0);
}

