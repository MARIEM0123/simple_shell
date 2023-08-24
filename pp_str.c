#include "shell.h"
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

