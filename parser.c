#include "shell.h"

/**
 * is_cmd - the function
 * @info: the parameter
 * @path: the parameter
 * Return: there is a return
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * string_duplic - the function
 * @pathstr: the parameter
 * @start: the parameter
 * @stop: the parameter
 * Return: there is a return
 */
char *string_duplic(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - the function
 * @info: the parameter
 * @pathstr: the parameter
 * @cmd: theparameter
 * Return: there is a return
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && init_func(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = string_duplic(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

/**
 * lib_g - the function
 * @ptr: the parameter
 * Return:vthere is a return
 */
int lib_g(void **ptr)
{
        if (ptr && *ptr)
        {
                free(*ptr);
                *ptr = NULL;
                return (1);
        }
        return (0);
}
