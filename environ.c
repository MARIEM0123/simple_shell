#include "shell.h"
/**
* _ myp_story – the function
 * @DATA: parametr
 *  Return: equal to 0
 */
int _myp_story(DATA_t *DATA)
{
        p_strings(DATA-> p_story);
        return (0);
}

/**
 * env_name – the function
 * @info: parameter
 * @l: the parameter
 * Return: !=0
 */
char *env_name(DATA_t *DATA, const char *l)
{
        STRRUCT_L *nds = DATA->evn;
        char *p;

        while (nds)
        {
                p = abd(nds->str, l);
                if (p && *p)
                        return (p);
                nds = nds->too;
        }
        return (NULL);
}
/**
 * rm_env – the function
 * @DATA:  parameter
 * Return: equal to 0
 */
int rm_env(DATA_t *DATA)
{
        int k;

        if (DATA->argc == 1)
        {
                _pputs("Error message\n");
                return (1);
        }
        for (k = 1; k <= DATA->argc; k++)
                rmp_env(DATA, DATA->argv[k]);

        return (0);
}

/**
 * env_sitting – the function
 * @DATA: the parameter
 *  Return: equal to 0
 */
int env_sitting(DATA_t *DATA)
{
        if (DATA->argc != 3)
        {
                _pputs("ERROR MESSAGE\n");
                return (1);
        }
        if (_init_env(DATA, DATA->argv[1], DATA->argv[2]))
                return (0);
        return (1);
}
/**
 * listing_env – the function
 * @DATA: the parameter
 * Return: there is a return
 */
int listing_env(DATA_t *DATA)
{
        STRRUCT_L *nds = NULL;
        size_t k;
        char **par_envv = NULL;

        for (k = 0; par_envv[k]; k++)
                add_nds_z(&nds, par_envv[k], 0);
        DATA->evn = nds;
        return (0);
}

