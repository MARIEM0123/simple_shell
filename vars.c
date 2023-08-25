#include "shell.h"
/**
 * VRFC – the function
 * @data: the parameter
 * @array: tha patrameter type array
 * @x: pointer
 * Return: there is a return
 */
int VRFC(DATA_t *DATA, char *array, size_t *x)
{
        size_t k = *x;

        if (array[k] == '|' && array[k + 1] == '|')
        {
                array[k] = 0;
                k++;
                DATA-> L_array_type = NUM_UN;
        }
        else if (array[k] == '&' && array[k + 1] == '&')
        {
                array[k] = 0;
                k++;
                DATA-> L_array_type = NUM_TWO   ;
        }
        else if (array[k] == ';')
        {
                array[k] = 0;
                DATA-> L_array_type = NUM_TREE;
        }
        else
                return (0);
        *x = k;
        return (1);
}
/**
 * VERIFIC – the function
 * @DATA: the parameter
 * @array: the array
 * @x: the parameter pointer
 * @c: the first case
 * @ll: the parameter
 * Return: there is a return
 */
void VERIFIC(DATA_t *DATA, char *array, size_t*x, size_t c, size_t ll)
{
        size_t k = *x;

        if (DATA->L_array_type == NUM_TWO)
        {
                if (DATA->etat)
                {
                        array[c] = 0;
                        k = ll;
                }
        }
        if (DATA->L_array_type == NUM_UN)
        {
                if (!DATA->etat)
                {
                        array[c] = 0;
                        k = ll;
                }
        }

        *x = k;
}
/**
 * alias_subt – the function to replace alias
 * @info: the parameter
 * Return: 1 ther is a return
 */
int alias_subt(DATA_t *DATA)
{
        int i;
        STRRUCT_L *nds;
        char *x;

        for (i = 0; i < 10; i++)
        {
                nds = str_nds(DATA->alias, DATA->argv[0], '=');
                if (!nds)
                        return (0);
                free(DATA->argv[0]);
                x = _strchr(nds->str, '=');
                if (!x)
                        return (0);
                x = _strdup(x + 1);
                if (!x)
                        return (0);
                DATA->argv[0] = x;
        }
        return (1);
}
/**
 * varias_subt – the function to replace variables
 * @DATA: the parameter
 *
 * Return: 1 if replaced, 0 otherwise
 */
int varias_subt(DATA_t *DATA)
{
        int i = 0;
        STRRUCT_L *nds;

        for (i = 0; DATA->argv[i]; i++)
        {
                if (DATA->argv[i][0] != '$' || !DATA->argv[i][1])
                        continue;

                if (!_strcompare(DATA->argv[i], "$?"))
                {
                        str_chg(&(DATA->argv[i]),
                                        _strdup(convert_number(DATA->etat, 10, 0)));
                        continue;
                }
                if (!_strcompare(DATA->argv[i], "$$"))
                {
                        str_chg(&(DATA->argv[i]),
                                        _strdup(convert_number(getpid(), 10, 0)));
                        continue;
                }
                nds = str_nds(DATA->evn, &DATA->argv[i][1], '=');
                if (nds)
                {
                        str_chg(&(DATA->argv[i]),
                                        _strdup(_strchr(nds->str, '=') + 1));
                        continue;
                }
                str_chg(&DATA->argv[i], _strdup(""));

        }
        return (0);
}
/**
 * str_chg – the function
 * @par1: parameter one
 * @par2: parameter two
 * Return: there is a return
 */
int str_chg(char **par1, char *par2)
{
        free(*par1);
        *par1 = par2;
        return (1);
}

