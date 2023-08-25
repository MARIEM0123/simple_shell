#include "shell.h"
/**
 * mode_intr – the function
 * @DATA: the parameter
 * Return: there is a return
 */
int mode_intr(DATA_t *DATA)
{
        return (isatty(STDIN_FILENO) && DATA->rddfile <= 2);
}
/**
 * the_delimiter – the function
 * @s: the parameter
 * @l: the parameter
 * Return: there is a erturn
 */
int the_delimiter(char s, char *l)
{
        while (*l)
                if (*l++ == s)
                        return (1);
        return (0);
}
/**
 * _isb - define the type of the char
 * @s: The input of the function
 * Return: the return is 1 if success or 0 in case of failure
 */

int _isb(int s)
{
        if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
                return (1);
        else
                return (0);
}

