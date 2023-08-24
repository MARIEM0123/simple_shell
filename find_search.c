#include "shell.h"
/**
 * abd – the function
 * @search: the parameter
 * @find: the parameter
 * Return: there is a return
 */
char *abd(const char *search, const char *find)
{
	while (*find)
		if (*find++ != *search++)
			return (NULL);
	return ((char *)search);
}
/**
 * srch_tab – the function
 * @DATA: the parametre
 * Return: depends on the case
 */
int srch_tab(DATA_t *DATA)
{
	int i, sch= -1;
	sch_table fnd[] = {
		{"exit", EXIT_FUNCT},
		{"evn", NW_ennv},
		{"help", ch_dir},
		{"p_story", _myp_story},
		{"setevn", env_sitting},
		{"unsetevn", rm_env},
		{"cd", ch_cur_dir},
		{"alias", _alias_},
		{NULL, NULL}
	};

	for (i = 0; fnd[i].yht; i++)
		if (_strcompare (DATA->argv[0], fnd[i].yht) == 0)
		{
			DATA->num_lines++;
			sch = fnd[i].gct(DATA);
			break;
		}
	return (sch);
}

