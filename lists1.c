#include "shell.h"
/**
 * linked_lgnt – the function
 * @x: parameter
 * Return: size of list
 */
size_t linked_lgnt(const STRRUCT_L *x)
{
        size_t k = 0;

        while (x)
        {
                x = x->too;
                k++;
        }
        return (k);
}
/**
 * stline – the function
 * @h: the parameter
 * Return: is the lenght
 */
int stline(char *h)
{
        int k = 0;

        if (!h)
                return (0);

        while (*h++)
                k++;
        return (k);
}
/**
* STRRUCT_Lo_strings – the function
 * @x: parameter
 * Return: !=0
 */
char **STRRUCT_Lo_strings(STRRUCT_L *x)
{
        STRRUCT_L *nds = x;
        size_t i = linked_lgnt(x), j;
        char **cc;
        char *c;

        if (!x || !i)
                return (NULL);
        cc = malloc(sizeof(char *) * (i + 1));
        if (!cc)
                return (NULL);
        for (i = 0; nds; nds = nds->too, i++)
        {
                c = malloc(_len_string(nds->str) + 1);
                if (!c)
                {
                        for (j = 0; j < i; j++)
                                free(cc[j]);
                        free(cc);
                        return (NULL);
                }

                c = _strcpy(c, nds->str);
                cc[i] = c;
        }
        cc[i] = NULL;
        return (cc);
}
/**
* str_nds – the funtion
 * @ nds: parameter
 * @l: parameter
 * @c: the parameter
 * Return: ther isb a return
 */
STRRUCT_L *str_nds(STRRUCT_L *nds, char *l, char c)
{
        char *x = NULL;

        while (nds)
        {
                x = abd(nds->str, l);
                if (x && ((c == -1) || (*x == c)))
                        return (nds);
                nds = nds->too;
        }
        return (NULL);
}
/**
 * nds_count – the function 
 * @par1: parameter
 * @nds: poarameter
 * Return: there is a return
 */
ssize_t nds_count(STRRUCT_L *par1, STRRUCT_L *nds)
{
        size_t k = 0;

        while (par1)
        {
                if (par1 == nds)
                        return (k);
                par1 = par1->too;
                k++;
        }
        return (-1);
}

