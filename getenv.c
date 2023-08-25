#include "shell.h"
/**
 * get_par_envv – the function
 * @DATA: parameter
 * Return: equal to 0
 */
char **get_par_envv(DATA_t *DATA)
{
        if (!DATA->par_envv || DATA->env_mod)
        {
                DATA->par_envv = STRRUCT_Lo_strings(DATA->evn);
                DATA->env_mod = 0;
        }
        return (DATA->par_envv);
}
/**
 * rmp_env – the function
 * @DATA: parameter
 *  Return: there is a return
 * @var: the string evn var property
 */
int rmp_env(DATA_t *DATA, char *x)
{
        STRRUCT_L *nds = DATA->evn;
        size_t k = 0;
        char *p;

        if (!nds || !x)
                return (0);

        while (nds)
        {
                p = abd(nds->str, x);
                if (p && *p == '=')
                {
                        DATA->env_mod = del_ndss(&(DATA->evn), k);
                        k = 0;
                        nds = DATA->evn;
                        continue;
                }
                nds = nds->too;
                k++;
        }
        return (DATA->env_mod);
}
/**
 * _init_env – the function
 * @DATA: Parameter
 * @a: the parameter
 * @b: the parameter
 *  Return: there isb a return
 */
int _init_env(DATA_t *DATA, char *a, char *b)
{
        char *array = NULL;
        STRRUCT_L *nds;
        char *p;

        if (!a || !b)
                return (0);

        array = malloc(_len_string(a) + _len_string(b) + 2);
        if (!array)
                return (1);
        _strcpy(array, a);
        _strcat(array, "=");
        _strcat(array, b);
        nds = DATA->evn;
        while (nds)
        {
                p = abd(nds->str, a);
                if (p && *p == '=')
                {
                        free(nds->str);
                        nds->str = array;
                        DATA-> env_mod = 1;
                        return (0);
                }
                nds = nds->too;
        }
        add_nds_z(&(DATA->evn), array, 0);
        free(array);
        DATA->env_mod = 1;
        return (0);
}
/**
 * init_new_env – the function
 * @DATA: parameter
 * @b: the parameter
 * @a: the parameter
 *  Return: equal to 0
 */
int init_new_env(DATA_t *DATA, char *b, char *a)
{
        char *array = NULL;
        STRRUCT_L *nds;
        char *p;

        if (!b || !a)
                return (0);

        array = malloc(stline(b) + stline(a) + 2);
        if (!array)
                return (1);
        _strcpy(array, b);
        _strcat(array, "=");
        _strcat(array, a);
        nds = DATA->evn;
        while (nds)
        {
                p = abd(nds->str, b);
                if (p && *p == '=')
                {
                        free(nds->str);
                        nds->str = array;
                        DATA->env_mod = 1;
                        return (0);
                }
                nds = nds->too;
        }
        add_nds_z(&(DATA->evn), array, 0);
        free(array);
        DATA->env_mod = 1;
        return (0);
}

