#include "shell.h"

/**
 * interactive - the function
 * @info: parameter
 *
 * Return: there is a rturn
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->file_rd <= 2);
}

/**
 * is_delim - the fun ction
 * @c: the parameter
 * @delim: the parameter
 * Return: there is a erturn
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha -the function
 * @c: The parameter
 * Return:there is a return
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - the function
 * @s: the parameter
 * Return: there is a return
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

