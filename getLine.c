#include "shell.h"

/**
 * input_buf - the function
 * @data: the parameter
 * @array: the parameter
 * @l: the parameter
 * Return: thereis a return
 */
ssize_t input_buf(info_t *data, char **array, size_t *l)
{
	ssize_t x = 0;
	size_t len_p = 0;

	if (!*l)
	{
		free(*array);
		*array = NULL;
		signal(SIGINT, sigintHandler);
#if CASE_GLN
		x = getline(array, &len_p, stdin);
#else
		x = _getline(data, array, &len_p);
#endif
		if (x > 0)
		{
			if ((*array)[x - 1] == '\n')
			{
				(*array)[x - 1] = '\0';
				x--;
			}
			data->numbers = 1;
			c_rm(*array);
			build_history_list(data, *array, data->num_stc++);
			{
				*l = x;
				data->arr_cmd = array;
			}
		}
	}
	return (x);
}

/**
 * get_input - the function
 * @info: the parameter
 * Return: there is a return
 */
ssize_t get_input(info_t *data)
{
	static char *array;
	static size_t i, j, l;
	ssize_t x = 0;
	char **buf_p = &(data->arg), *p;

	_putchar(BUF_FLUSH);
	x = input_buf(data, &array, &l);
	if (x == -1)
		return (-1);
	if (l)
	{
		j = i;
		p = array + i;

		check_chain(data, array, &j, i, l);
		while (j < l)
		{
			if (is_lchx(data, array, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= l)		{
			i = l = 0;
			data->arr_cmdt = ZERO_NUM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = array;
	return (x);
}

/**
 * read_buf - the function
 * @data:the parameter
 * @array: the parameter
 * @i: :!= 0
 * Return: there is a return
 */
ssize_t read_buf(info_t *data, char *array, size_t *i)
{
	ssize_t x = 0;

	if (*i)
		return (0);
	x = read(data->file_rd, array, READ_BUF_SIZE);
	if (x >= 0)
		*i = x;
	return (x);
}

/**
 * _getline - the function
 * @data: parameter
 * @y:the parameter
 * @l: there is a erturn
 * Return: teher is a return
 */
int _getline(info_t *data, char **y, size_t *l)
{
	static char array[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t x = 0, s = 0;
	char *p = NULL, *q = NULL, *c;

	p = *y;
	if (p && l)
		s = *l;
	if (i == len)
		i = len = 0;

	x = read_buf(data, array, &len);
	if (x == -1 || (x == 0 && len == 0))
		return (-1);

	c = hr_str(array + i, '\n');
	k = c ? 1 + (unsigned int)(c - array) : len;
	q = _realloc(p, s, s ? s + k : k + 1);
	if (!q)
		return (p ? free(p), -1 : -1);

	if (s)
		_strrcat(q, array + i, k - i);
	else
		_strrcpy(q, array + i, k - i + 1);

	s += k - i;
	i = k;
	p = q;

	if (l)
		*l = s;
	*y = p;
	return (s);
}

/**
 * sigintHandler - the function
 * @sig_num: the parameter
 * Return: there is a return
 */
void sigintHandler(__attribute__((unused))int sign_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

