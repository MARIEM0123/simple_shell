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
			error_output(DATA, "Illegal number: ");
			_entry(DATA->argv[1]);
			_pprtchar('\n');
			return (1);
		}
		DATA->increm = amoi(DATA->argv[1]);
		return (-2);
	}
	DATA->increm = -1;
	return (-2);
}

