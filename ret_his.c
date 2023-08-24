#include "shell.h"
/**
 * ret_story_fd - function
 * @DATA: parameter
 * Return: there is a return
 */

char *ret_story_fd(DATA_t *DATA)
{
	char *array, *x;

	x = ev_value(DATA, "HOME=");
	if (!x)
		return (NULL);
	array = malloc(sizeof(char) * (stline(x) + stline(MESS_STORY) + 2));
	if (!array)
		return (NULL);
	array[0] = 0;
	_strcpy(array, x);
	_strcat(array, "/");
	_strcat(array, MESS_STORY);
	return (array);
}
