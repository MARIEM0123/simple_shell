#include "shell.h"

/**
 * hsh - function
 * @DATA: the parameter
 * @b: the parameter
 * Return: there is a return
 */
int hsh(DATA_t *DATA, char **b)
{
        ssize_t x = 0;
        int a = 0;

        while (x != -1 && a != -2)
        {
                data_net (DATA);
                if (mode_intr(DATA))
                        _puts("$ ");
                _pputchar(MIINUSONE);
                x = p_input_line(DATA);
                if (x != -1)
                {
                        DATA_star(DATA, b);
                        a = srch_tab(DATA);
                        if (a == -1)
                        ex_comm(DATA);
                }
                else if (mode_intr(DATA))
                        _putchar('\n');
                lib_DATA(DATA, 0);
        }
        rw_p_story(DATA);
        lib_DATA(DATA, 1);
        if (!mode_intr(DATA) && DATA->etat)
                exit(DATA->etat);
        if (a == -2)
        {
                if (DATA->increm == -1)
                        exit(DATA->etat);
                exit(DATA->increm);
        }
        return (a);
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
                                err_output(DATA, "Error message\n");
                }
        }
}

