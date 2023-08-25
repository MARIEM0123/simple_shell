#include "shell.h"
/**
 * NW_ennv – get the evnirnmnt
 * @DATA: the parameter
 * Return: tge return is 0
 */
int NW_ennv(DATA_t *DATA)
{
        p_strings(DATA->evn);
        return (0);
}
/**
 * alias_c – the function
 * @DATA: parameter
 * @ch: the parameter
 * Return: there is a return
 */
int alias_c (DATA_t *DATA, char *ch)
{
        char *l, c;
        int x;

        l = _strchr(ch, '=');
        if (!l)
                return (1);
        c = *l;
        *l = 0;
        x = del_ndss(&(DATA->alias),
                nds_count(DATA->alias, str_nds(DATA->alias, ch, -1)));
        *l = c;
        return (x);
}
/**
 * alias_init- the function
 * @DATA: parameter
 * @c: the parameter
 * Return: ther is a return
 */
int alias_init (DATA_t *DATA, char *c)
{
        char *x;

        x = _strchr(c, '=');
        if (!x)
                return (1);
        if (!*++x)
                return (alias_c(DATA, c));

        alias_c(DATA, c);
        return (add_nds_z(&(DATA->alias), c, 0) == NULL);
}
/**
 * alias_input – the function
 * @nds: the parameter
 * Return: there is a return
 */
int alias_input(STRRUCT_L *nds)
{
        char *x = NULL;
char *b = NULL;

        if (nds)
        {
                x = _strchr(nds->str, '=');
                for (b = nds->str; b <= x; b++)
                _putchar(*b);
                _putchar('\'');
                _puts(x + 1);
                _puts("'\n");
                return (0);
        }
        return (1);
}
/**
 *  _alias_ - the function
 * @DATA: parameter
 *  Return: equal to 0
 */
int  _alias_(DATA_t *DATA)
{
        int k = 0;
        char *p = NULL;
        STRRUCT_L *nds = NULL;

        if (DATA->argc == 1)
        {
                nds = DATA->alias;
                while (nds)
                {
                        alias_input(nds);
                        nds = nds->too;
                }
                return (0);
        }
        for (k = 1; DATA->argv[k]; k++)
        {
                p = _strchr(DATA->argv[k], '=');
                if (p)
                        alias_init(DATA, DATA->argv[k]);
                else
                        alias_input(str_nds(DATA->alias, DATA->argv[k], '='));
        }

        return (0);
}

