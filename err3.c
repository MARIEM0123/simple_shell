#include "shell.h"
#include <limits.h>
/**
 * amoi – the function for conversion
 * @c: the parameter
 * Return: 0the is a return
 */
int amoi(char *c)
{
	int inc = 0;
	unsigned long int outputt = 0;

	if (*c == '+')
		c++;
	for (inc = 0;  c[inc] != '\0'; inc++)
	{
		if (c[inc] >= '0' && c[inc] <= '9')
		{
			outputt *= 10;
			outputt += (c[inc] - '0');
			if (outputt > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (outputt);
}

/**
 * p_dtt – the function for a type of numbers
 * @input: the parameter to start
 * @ffile: the file name of the descriptor
 * Return: the is a return
 */
int p_dtt(int input, int ffile)
{
	int (*__putchar)(char) = _putchar;
	int k, kk = 0;
	unsigned int _abs_, NW;

	if (ffile == STDERR_FILENO)
		__putchar = _pprtchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		kk++;
	}
	else
		_abs_ = input;
	NW = _abs_;
	for (k = 1000000000; k > 1; k /= 10)
	{
		if (_abs_ / k)
		{
			__putchar('0' + NW / k);
			kk++;
		}
		NW %= k;
	}
	__putchar('0' + NW);
	kk++;

	return (kk);
}

