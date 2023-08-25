#include "shell.h"
/**
 * add_nds_z – the function
 * @h: tha parameter
 * @ch: the parameter
 * @num: parameyer
 * Return: there is a return
 */
STRRUCT_L *add_nds_z(STRRUCT_L **h, const char *ch, int num)
{
        STRRUCT_L *new_nds, *nds;

        if (!h)
                return (NULL);

        nds = *h;
        new_nds = malloc(sizeof(STRRUCT_L));
        if (!new_nds)
                return (NULL);
        _memset((void *)new_nds, 0, sizeof(STRRUCT_L));
        new_nds->num = num;
        if (ch)
        {
                new_nds->str = _strdup(ch);
                if (!new_nds->str)
                {
                        free(new_nds);
                        return (NULL);
                }
        }
        if (nds)
        {
                while (nds->too)
                        nds = nds->too;
                nds->too = new_nds;
        }
        else
                *h = new_nds;
        return (new_nds);
}
/**
 * p_strings – the function
 * @p: the parameter
 * Return: ther is a return
 */
size_t p_strings(const STRRUCT_L *p)
{
        size_t k = 0;

        while (p)
        {
                _puts(p->str ? p->str : "(nil)");
                _puts("\n");
                p = p->too;
                k++;
        }
        return (k);
}
/**
 * del_ndss – the function
 * @h: parameter
 * @k: parameter
 * Return: there is a return
 */
int del_ndss(STRRUCT_L **h, unsigned int k)
{
        STRRUCT_L *nds, *x_nds;
        unsigned int i = 0;

        if (!h || !*h)
                return (0);

        if (!k)
        {
                nds = *h;
                *h = (*h)->too;
                free(nds->str);
                free(nds);
                return (1);
        }
        nds = *h;
        while (nds)
        {
                if (i == k)
                {
                        x_nds->too = nds->too;
                        free(nds->str);
                        free(nds);
                        return (1);
                }
                i++;
                x_nds = nds;
                nds = nds->too;
        }
        return (0);
}
/**
 *lib_data -    the function
 * @x: 
 * Return: void
 */
void lib_data(STRRUCT_L **x)
{
        STRRUCT_L *nds, *too_nds, *h;

        if (!x || !*x)
                return;
        h = *x;
        nds = h;
        while (nds)
        {
                too_nds = nds->too;
                free(nds->str);
                free(nds);
                nds = too_nds;
        }
        *x = NULL;
}

