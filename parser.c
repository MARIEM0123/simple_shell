#include "shell.h"

/**
 * is_cmd - the function
 * @data: the parameter
 * @link: the parameter
 * Return: there is a return
 */
int is_cmd(info_t *data, char *link)
{
	struct stat st;

	(void)data;
	if (!link || stat(link, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * string_duplic - the function
 * @link: the parameter
 * @s1: the parameter
 * @s2: the parameter
 * Return: there is a return
 */
char *string_duplic(char *link, int s1, int s2)
{
	static char array[1024];
	int i = 0, k = 0;

	for (k = 0, i = s1; i < s2; i++)
		if (link[i] != ':')
			array[k++] = link[i];
	array[k] = 0;
	return (array);
}

/**
 * find_path - the function
 * @info: the parameter
 * @pathstr: the parameter
 * @cmd: theparameter
 * Return: there is a return
 */
char *find_path(info_t *data, char *link, char *x)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!link)
		return (NULL);
	if ((_strlen(x) > 2) && init_func(x, "./"))
	{
		if (is_cmd(data, x))
			return (x);
	}
	while (1)
	{
		if (!link[i] || link[i] == ':')
		{
			path = string_duplic(link, curr_pos, i);
			if (!*path)
				_strcat(path, x);
			else
			{
				_strcat(path, "/");
				_strcat(path, x);
			}
			if (is_cmd(data, path))
				return (path);
			if (!link[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

/**
 * lib_g - the function
 * @ss: the parameter
 * Return:vthere is a return
 */
int lib_g(void **ss)
{
        if (ss && *ss)
        {
                free(*ss);
                *ss = NULL;
                return (1);
        }
        return (0);
}
