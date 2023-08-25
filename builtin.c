#include "shell.h"
/**
 * EXIT_FUNCT – THE FUNCTION TO MAKE THE EXIT
 * @DATA: THE ARGUMENTS
 * Return: the function to exit
 */
int EXIT_FUNCT(DATA_t *DATA)
{
        int quit;

        if (DATA->argv[1])
        {
                quit = amoi(DATA->argv[1]);
                if (quit == -1)
                {
                        DATA->etat = 2;
                        err_output(DATA, "Error message: ");
                        _pputs(DATA->argv[1]);
                        _pputchar('\n');
                        return (1);
                }
                DATA->increm = amoi(DATA->argv[1]);
                return (-2);
        }
        DATA->increm = -1;
        return (-2);
}
/**
 * ch_cur_dir – the function
 * @DATA: parameter 
 * Return: equal to 0
 */
int ch_cur_dir(DATA_t *DATA)
{
        char *s, *x, array[1024];
        int xx;

        s = getcwd(array, 1024);
        if (!s)
                _puts("TODO: >>Error message <<\n");
        if (!DATA->argv[1])
        {
                x = env_name(DATA, "HOME=");
                if (!x)
                        xx = chdir((x = env_name(DATA, "PWD=")) ? x : "/");
                else
                        xx = chdir(x);
        }
        else if (_strcompare(DATA->argv[1], "-") == 0)
        {
                if (!env_name(DATA, "OLDPWD="))
                {
                        _puts(s);

_putchar('\n');
                        return (1);
                }
                _puts(env_name(DATA, "OLDPWD=")), _putchar('\n');
                xx = chdir((x = env_name(DATA, "OLDPWD=")) ? x : "/");
        }
        else
                xx = chdir(DATA->argv[1]);
        if (xx == -1)
        {
                err_output(DATA, "Error message ");
                _pputs(DATA->argv[1]), _pputchar('\n');
        }
        else
        {
                init_new_env(DATA, "OLDPWD", env_name(DATA, "PWD="));
                init_new_env(DATA, "PWD", getcwd(array, 1024));
        }
        return (0);
}
/**
 * ch_dir – the function
 * @DATA: the parameter
 * Return: equal to 0
 */
int ch_dir(DATA_t *DATA)
{
        char **array;

        array = DATA->argv;
        _puts("Error message \n");
        if (0)
                _puts(*array);
        return (0);
}

