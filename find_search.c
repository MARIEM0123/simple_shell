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
/**
 * ex_comm – the function
 * @DATA: the parameter
 * Return: != 0
 */
void ex_comm(DATA_t *DATA)
{
	pid_t dp;

	dp = fork();
	if (dp == -1)
	{
	
		perror("Error message:");
		return;
	}
	if (dp == 0)
	{
		if (execve(DATA->path, DATA->argv, get_par_envv(DATA)) == -1)
		{
			lib_DATA(DATA, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(DATA->etat));
		if (WIFEXITED(DATA->etat))
		{
			DATA->etat = WEXITSTATUS (DATA->etat);
			if (DATA->etat == 126)
				error_output(DATA, "Error message\n");
		}
	}
}
/**
 * get_par_envv – the function
 * @DATA: parameter
 * Return: equal to 0
 */
char **get_par_envv(DATA_t *DATA)
{
	if (!DATA->par_envv || DATA->env_mod)
	{
		DATA->par_envv = STRRUCT_Lo_strings(DATA->evn);
		DATA->env_mod = 0;
	}

	return (DATA->par_envv);
}
/**
 * STRRUCT_Lo_strings – the function
 * @x: parameter
 * Return: !=0
 */
char **STRRUCT_Lo_strings(STRRUCT_L *x)
{
	STRRUCT_L *nds = x;
	size_t i = linked_lgnt(x), j;
	char **cc;
	char *c;

	if (!x || !i)
		return (NULL);
	cc = malloc(sizeof(char *) * (i + 1));
	if (!cc)
		return (NULL);
	for (i = 0; nds; nds = nds->too, i++)
	{
		c = malloc(stline(nds->c) + 1);
		if (!c)
		{
			for (j = 0; j < i; j++)
				free(c[j]);
			free(cc);
			return (NULL);
		}

		c = _strcpy(c, nds->str);
		cc[i] = c;
	}
	cc[i] = NULL;
	return (cc);
}

