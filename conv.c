#include "shell.h"
/**
 * convert_number – the function
 * @num: the parameter
 * @sprt: parameter
 * @parmt: paramzttere
 * Return: the is a return different 0
 */
char *convert_number(long int L, int sprt, int parmt)
{
	static char *array;
	static char arrayfer[50];
	char mm = 0;
	char *ptr;
	unsigned long n = L;

	if (!(parmt & CONVERT_UNSIGNED) && L < 0)
	{
		n = -L;
		mm = '-';

	}
	array = parmt & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &arrayfer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % sprt];
		n /= sprt;
	} while (n != 0);

	if (mm)
		*--ptr = mm;
	return (ptr);
}

