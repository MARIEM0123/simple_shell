#include "shell.h"

/**
 *  _atoi2 - the function
 * @c: the parameter
 * Return: ther is a return
 */
int _atoi2(char *c)
{
	int k = 0;
	unsigned long int pt = 0;

	if (*c == '+')
		c++;
	for (k = 0;  c[k] != '\0'; k++)
	{
		if (c[k] >= '0' && c[k] <= '9')
		{
			pt *= 10;
			pt += (c[k] - '0');
			if (pt > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (pt);
}

/**
 * err_output - the function
 * @data: the parameter
 * @y: parameter
 * Return:thetre is a return
 */
void err_output(info_t *data, char *y)
{
	_eputs(data->nfd);
	_eputs(": ");
	d_output(data->lnumber, STDERR_FILENO);
	_eputs(": ");
	_eputs(data->argv[0]);
	_eputs(": ");
	_eputs(y);
}

/**
 * d_output - the function
 * @e: the parameter
 * @file: the parameter
 * Return: there is a return
 */
int d_output(int e, int file)
{
	int (*__putchar)(char) = _putchar;
	int k, n = 0;
	unsigned int _abs_, nw;

	if (file == STDERR_FILENO)
		__putchar = _eputchar;
	if (e < 0)
	{
		_abs_ = -e;
		__putchar('-');
		n++;
	}
	else
		_abs_ = e;
	nw = _abs_;
	for (k = 1000000000; k > 1; k /= 10)
	{
		if (_abs_ / k)
		{
			__putchar('0' + nw / k);
			n++;
		}
		nw %= k;
	}
	__putchar('0' + nw);
	n++;

	return (n);
}

/**
 * n_conv - the function
 * @n:the parameter
 * @b: the parameter
 * @a: the parameter
 * Return: thhere is a return
 */
char *n_conv(long int m, int b, int a)
{
	static char *array;
	static char arr[50];
	char mm = 0;
	char *ss;
	unsigned long n = m;

	if (!(a &CASE_US_CONV) && m < 0)
	{
		n = -m;
		mm = '-';

	}
	array = a & CASE_CONV ? "0123456789abcdef" : "0123456789ABCDEF";
	ss = &arr[49];
	*ss = '\0';

	do	{
		*--ss = array[n % b];
		n /= b;
	} while (n != 0);

	if (mm)
		*--ss = mm;
	return (ss);
}

/**
 * c_rm - the function
 * @arr: the parameter
 * Return: the return is thetre
 */
void c_rm(char *arr)
{
	int k;

	for (k = 0; arr[k] != '\0'; k++)
		if (arr[k] == '#' && (!k || arr[k - 1] == ' '))
		{
			arr[k] = '\0';
			break;
		}
}

