#include "shell.h"
/**
 * input_array – the function
 * @DATA: the input data
 * @array: the array 
 * @l: the parameter
 * Return: the is a return different th 0
 */
ssize_t input_array(DATA_t *DATA, char **array, size_t*l)
{
        ssize_t x = 0;
        size_t hau = 0;

        if (!*l)
        {
                free(*array);
                *array = NULL;
                signal(SIGINT, handle_var);
#if USE_LINE_PARM
                x = line_parm(array, &hau, stdin);
#else
                x = _line_parm(DATA, array, &hau);
#endif
                if (x > 0)
                {
                        if ((*array)[x - 1] == '\n')
                        {
                                (*array)[x - 1] = '\0';
                                x--;
                        }
                        DATA->linekk_flag = 1;
                        rm_ct(*array);
                        h_his(DATA, *array, DATA->histkk++);
                        {
                                *l = x;
                                DATA->L_array = array;
                        }
                }
        }
        return (x);
}
/**
 * p_input_line – operation on the lines
 * @DATA: the structure given
 * Return: is different that NULL
 */
ssize_t p_input_line(DATA_t *DATA)
{
        static char *array;
        static size_t j, i, l;
        ssize_t x = 0;
        char **array_p = &(DATA->arg), *p;

        _putchar(MIINUSONE);
        x = input_array(DATA, &array, &l);
        if (x == -1)
                return (-1);
        if (l)
        {
                j = i;
                p = array + i;

                VERIFIC(DATA, array, &j, i, l);
                while (j < l) 
                {
                        if (VRFC(DATA, array, &j))
                                break;
                        j++;
                }

                i = j + 1;
                if (i >= l)
                {
                        i = l = 0;
                        DATA->L_array_type = ZERO_NUM;
                }

                *array_p = p;
                return (stline(p));
        }

        *array_p = array;
        return (x);
}
/**
 * d_array- the function
 * @DATA: the paraleter
 * @array: the parameter
 * @i: the parameter
 * Return: the is a return
 */
ssize_t d_array(DATA_t *DATA, char *array, size_t *i)
{
        ssize_t x = 0;

        if (*i)
                return (0);
        x = read(DATA->rddfile, array, MAX_ARRAY_NUM);
        if (x >= 0)
                *i = x;
        return (x);
}
/**
 * _line_parm – operation on the lines
 * @DATA: tha parameter
 * @ptr: the parameter pointer
 * @l: the length of the parameter
 * Return: the is a return
 */
int _line_parm(DATA_t *DATA, char **pp, size_t *l)
{
        static char array[MAX_ARRAY_NUM];
        static size_t i, g;
        size_t k;
        ssize_t r = 0, str = 0;
        char *a = NULL, *new_p = NULL, *c;

        a = *pp;
        if (a && l)
                str = *l;
        if (i == g)
                i = g = 0;

        r = d_array(DATA, array, &g);
        if (r == -1 || (r == 0 && g == 0))
                return (-1);

        c = _strchr(array + i, '\n');
        k = c ? 1 + (unsigned int)(c - array) : g;
        new_p = _realloc(a, str, str ? str + k : k + 1);
        if (!new_p) 
                return (a ? free(a), -1 : -1);

        if (str)
                _strncat(new_p, array + i, k - i);
        else
                _strncpy(new_p, array + i, k - i + 1);

        str += k - i;
        i = k;
        a = new_p;

        if (l)
                *l = str;
        *pp = a;
        return (str);
}
/**
 * handle_var - he function
 * @c: parameter
 * Return: there is a return
 */
void handle_var(__attribute__((unused))int c)
{
        _puts("\n");
        _puts("$ ");
        _putchar(MIINUSONE);
}

