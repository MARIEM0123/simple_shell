#include "shell.h"

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
