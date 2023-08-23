#include "shell.h"
/**
 * _isb - define the type of the char
 * @s: The input of the function
 * Return: the return is 1 if success or 0 in case of failure
 */

int _isb(int s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
		return (1);
	else
		return (0);
}
