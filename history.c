#include "shell.h"

/**
 * get_history_file - the defined function
 * @info: parameter defined
 * Return: there is a retur,n
 */

char *get_history_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(MESS_DEF) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, MESS_DEF);
	return (buf);
}

/**
 * write_history - this is the defined function
 * @info: the parameter defined in her
 * Return: the return is different than  0
 */
int write_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);
	data_l *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->sth; node; node = node->next)
	{
		_fileputs(node->rst, fd);
		_fileput('\n', fd);
	}
	_fileput(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_history - The function is defined hree
 * @info: the parameteros defined here
 * Return: there is a return is deifferent that 0
 */
int read_history(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->num_stc = linecount;
	while (info->num_stc-- >= NUM_MAXIMUM)
		delete_node_at_index(&(info->sth), 0);
	renumber_history(info);
	return (info->num_stc);
}

/**
 * build_history_list - the function is defined here
 * @info: the parameter is definedd hhere
 * @buf: the parameter is defined here
 * @linecount: the parameter is defined here
 * Return: the return is equal to 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	data_l *node = NULL;

	if (info->sth)
		node = info->sth;
	add_node_end(&node, buf, linecount);

	if (!info->sth)
		info->sth = node;
	return (0);
}

/**
 * renumber_history - THE functioni is defined here
 * @info: the parameter is defined here
 * Return: the return is diffrent that null
 */
int renumber_history(info_t *info)
{
	data_l *node = info->sth;
	int i = 0;

	while (node)
	{
		node->runem = i++;
		node = node->next;
	}
	return (info->num_stc = i);
}

