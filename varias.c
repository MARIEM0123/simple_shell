#include "shell.h"
/**
 * varias_subt – the function to replace variables
 * @DATA: the parameter
 *
 * Return: 1 if replaced, 0 otherwise
 */
int varias_subt(DATA_t *DATA)
{
	int i = 0;
	STRRUCT_L *nds;

	for (i = 0; DATA->argv[i]; i++)
	{
		if (DATA->argv[i][0] != '$' || !DATA->argv[i][1])
			continue;

		if (!_strcmp(DATA->argv[i], "$?"))
		{
			str_chg(&(info->argv[i]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			str_chg(&(info->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		nds = str_nds(info->env, &info->argv[i][1], '=');
		if (nds)
		{
			str_chg(&(info->argv[i]),
					_strdup(_strchr(nds->str, '=') + 1));
			continue;
		}
		str_chg(&DATA->argv[i], _strdup(""));

	}
	return (0);
}
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
/**
 * str_chg – the function
 * @par1: parameter one
 * @par2: parameter two
 * Return: there is a return
 */
int str_chg(char **par1, char *par2)
{
	free(*par1);
	*par1 = par2;
	return (1);
}

