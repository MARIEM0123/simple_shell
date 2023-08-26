#include "shell.h"

/**
 * get_history_file - the defined function
 * @data: parameter defined
 * Return: there is a retur,n
 */

char *get_history_file(info_t *data)
{
	char *arr, *x;

	x = _getenv(data, "HOME=");
	if (!x)
		return (NULL);
	arr = malloc(sizeof(char) * (_strlen(x) + _strlen(MESS_DEF) + 2));
	if (!arr)
		return (NULL);
	arr[0] = 0;
	_strcpy(arr, x);
	_strcat(arr, "/");
	_strcat(arr, MESS_DEF);
	return (arr);
}

/**
 * write_history - this is the defined function
 * @data: the parameter defined in her
 * Return: the return is different than  0
 */
int write_history(info_t *data)
{
	ssize_t file;
	char *n = get_history_file(data);
	data_l *nds = NULL;

	if (!n)
		return (-1);

	file = open(n, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(n);
	if (file == -1)
		return (-1);
	for (nds = data->sth; nds; nds = nds->next)
	{
		_fileputs(nds->rst, file);
		_fileput('\n', file);
	}
	_fileput(BUF_FLUSH, file);
	close(file);
	return (1);
}
/**
 * build_history_list - the function is defined here
 * @data: the parameter is definedd hhere
 * @arr: the parameter is defined here
 * @m: the parameter is defined here
 * Return: the return is equal to 0
 */
int build_history_list(info_t *data, char *arr, int m)
{
        data_l *nds = NULL;

        if (data->sth)
                nds = data->sth;
        add_node_end(&nds, arr, m);

        if (!data->sth)
                data->sth = nds;
        return (0);
}
/**
 * read_history - The function is defined hree
 * @data: the parameteros defined here
 * Return: there is a return is deifferent that 0
 */
int read_history(info_t *data)
{
	int i, z = 0, m = 0;
	ssize_t file, rdlen, fz = 0;
	struct stat st;
	char *arr = NULL, *fl = get_history_file(data);

	if (!fl)
		return (0);

	file = open(fl, O_RDONLY);
	free(fl);
	if (file == -1)
		return (0);
	if (!fstat(file, &st))
		fz = st.st_size;
	if (fz < 2)
		return (0);
	arr = malloc(sizeof(char) * (fz + 1));
	if (!arr)
		return (0);
	rdlen = read(file, arr, fz);
	arr[fz] = 0;
	if (rdlen <= 0)
		return (free(arr), 0);
	close(file);
	for (i = 0; i < fz; i++)
		if (arr[i] == '\n')
		{
			arr[i] = 0;
			build_history_list(data, arr + z, m++);
			z = i + 1;
		}
	if (z != i)
		build_history_list(data, arr + z, m++);
	free(arr);
	data->num_stc = m;
	while (data->num_stc-- >= NUM_MAXIMUM)
		nds_dl(&(data->sth), 0);
	renumber_history(data);
	return (data->num_stc);
}


/**
 * renumber_history - THE functioni is defined here
 * @data: the parameter is defined here
 * Return: the return is diffrent that null
 */
int renumber_history(info_t *data)
{
	data_l *nds = data->sth;
	int i = 0;

	while (nds)
	{
		nds->runem = i++;
		nds = nds->next;
	}
	return (data->num_stc = i);
}

