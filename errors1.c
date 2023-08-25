#include "shell.h"
/**
 * amoi – the function for conversion
 * @c: the parameter
 * Return: 0the is a return
 */
int amoi(char *c)
{
        int inc = 0;
        unsigned long int outputt = 0;

        if (*c == '+')
                c++;
        for (inc = 0;  c[inc] != '\0'; inc++)
        {
                if (c[inc] >= '0' && c[inc] <= '9')
                {
                        outputt *= 10;
                        outputt += (c[inc] - '0');
                        if (outputt > INT_MAX)
                                return (-1);
                }
                else
                        return (-1);
        }
        return (outputt);
}

/**
 * err_output- the function
 * @DATA: the parameter
 * @x: parameter
 * Return: equal to 0 or 1
 */
void err_output(DATA_t *DATA, char *x)
{
        _pputs(DATA->fpnn);
        _pputs(": ");
        p_dtt(DATA-> num_lines, STDERR_FILENO);
        _pputs(": ");
        _pputs(DATA->argv[0]);
        _pputs(": ");
        _pputs(x);
}
#include <limits.h>

/**
 * p_dtt – the function for a type of numbers
 * @input: the parameter to start
 * @ffile: the file name of the descriptor
 * Return: the is a return
 */
int p_dtt(int input, int ffile)
{
        int (*__putchar)(char) = _putchar;
        int k, kk = 0;
        unsigned int _abs_, NW;

        if (ffile == STDERR_FILENO)
                __putchar = _pputchar;
        if (input < 0)
        {
                _abs_ = -input;
                __putchar('-');
                kk++;
        }
        else
                _abs_ = input;
        NW = _abs_;
        for (k = 1000000000; k > 1; k /= 10)
        {
                if (_abs_ / k)
                {
                        __putchar('0' + NW / k);
                        kk++;
                }
                NW %= k;
        }
        __putchar('0' + NW);
        kk++;

        return (kk);
}
/**
 * convert_number – the function
 * @num: the parameter
 * @sprt: parameter
 * @parmt: paramzttere
 * Return: the is a return different 0
 */
char *convert_number(long int L, int sprt, int parmt)
{
        static char *array;
        static char arrayfer[50];
        char mm = 0;
        char *ptr;
        unsigned long n = L;

        if (!(parmt & CONVERT_UNSIGNED) && L < 0)
        {
                n = -L;
                mm = '-';

        }
        array = parmt & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
        ptr = &arrayfer[49];
        *ptr = '\0';

        do      {
                *--ptr = array[n % sprt];
                n /= sprt;
        } while (n != 0);

        if (mm)
                *--ptr = mm;
        return (ptr);
}
/**
 * rm_ct – the function
 * @array: the parameter
 * Return: null
 */
void rm_ct(char *array)
{
        int x;

        for (x = 0; array[x] != '\0'; x++)
                if (array[x] == '#' && (!x || array[x - 1] == ' '))
                {
                        array[x] = '\0';
                        break;
                }
}

