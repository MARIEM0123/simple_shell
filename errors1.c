#include "shell.h"

/**
 *  _atoi2 - the function
 * @s: the parameter
 * Return: ther is a return
 */
int _atoi2(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * err_output - the function
 * @info: the parameter
 * @estr: parameter
 * Return:thetre is a return
 */
void err_output(info_t *info, char *estr)
{
	_eputs(info->nfd);
	_eputs(": ");
	d_output(info->lnumber, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * d_output - the function
 * @input: the parameter
 * @fd: the parameter
 * Return: there is a return
 */
int d_output(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * n_conv - the function
 * @num:the parameter
 * @base: the parameter
 * @flags: the parameter
 * Return: thhere is a return
 */
char *n_conv(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags &CASE_US_CONV) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CASE_CONV ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * c_rm - the function
 * @buf: the parameter
 * Return: the return is thetre
 */
void c_rm(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}

