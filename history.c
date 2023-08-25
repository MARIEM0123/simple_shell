#include "shell.h"
/**
 * ret_story_fd - function
 * @DATA: parameter
 * Return: there is a return
 */

char *ret_story_fd(DATA_t *DATA)
{
        char *array, *x;

        x = env_name(DATA, "HOME=");
        if (!x)
                return (NULL);
        array = malloc(sizeof(char) * (stline(x) + stline(MESS_STORY) + 2));
        if (!array)
                return (NULL);
        array[0] = 0;
        _strcpy(array, x);
        _strcat(array, "/");
        _strcat(array, MESS_STORY);
        return (array);
}

/**
 * rw_p_story – the function
 * @DATA: the parameter
 * Return: there is a return
 */
int rw_p_story(DATA_t *DATA)
{
        ssize_t ffile;
        char *filepnn = ret_story_fd(DATA);
        STRRUCT_L *nds = NULL;

        if (!filepnn)
                return (-1);

        ffile = open(filepnn, O_CREAT | O_TRUNC | O_RDWR, 0644);
        free(filepnn);
        if (ffile == -1)
                return (-1);
        for (nds = DATA->p_story; nds; nds = nds->too)
        {
                _putsffile(nds->str, ffile);
                _putffile('\n', ffile);
        }
        _putffile(MIINUSONE, ffile);
        close(ffile);
        return (1);
}
/**
 * pp_stry – the fub=nction
 * @DATA: the parameter
 *
 * Return: ther is a return
 */
int pp_stry(DATA_t *DATA)
{
        int k, z = 0, linekk = 0;
        ssize_t ffile, rdlen, fsize = 0;
        struct stat st;
        char *array = NULL, *filepnn = ret_story_fd(DATA);

        if (!filepnn)
                return (0);

        ffile = open(filepnn, O_RDONLY);
        free(filepnn);
        if (ffile == -1)
                return (0);
        if (!fstat(ffile, &st))
                fsize = st.st_size;
        if (fsize < 2)
                return (0);
        array = malloc(sizeof(char) * (fsize + 1));
        if (!array)
                return (0);
        rdlen = read(ffile, array, fsize);
        array[fsize] = 0;
        if (rdlen <= 0)
                return (free(array), 0);
        close(ffile);
        for (k = 0; k < fsize; k++)
                if (array[k] == '\n')
                {
                        array[k] = 0;
                        h_his(DATA, array + z, linekk++);
                        z = k + 1;
                }
        if (z != k)
                h_his(DATA, array + z, linekk++);
        free(array);
        DATA->histkk = linekk;
        while (DATA->histkk-- >= HIST_MAX)
                del_ndss(&(DATA->p_story), 0);
        don_p_story(DATA);
        return (DATA->histkk);
}
#include <stddef.h>
/**
 * h_his – the function
 * @DATA: the parameter
 * @array: the array parameter
 * @linekk: parameter
 * Return: is equal to 0
 */
int h_his(DATA_t *DATA, char *array, int linekk)
{
        STRRUCT_L *nds = NULL;

        if (DATA->p_story)
                nds = DATA->p_story;
        add_nds_z(&nds, array, linekk);

        if (!DATA->p_story)
                DATA->p_story = nds;
        return (0);
}
/**
 * don_p_story – the function
 * @DATA: the parameter
 * Return: there is a return
 */
int don_p_story(DATA_t *DATA)
{
        STRRUCT_L *nds = DATA->p_story;
        int i = 0;

        while (nds)
        {
                nds->num = i++;
                nds = nds->too;
        }
        return (DATA->histkk = i);
}

