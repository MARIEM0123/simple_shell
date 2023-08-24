#include "shell.h"

/**
 * main - entry point
 * @a: arg parameter
 * @b: arg array
 *
 * Return: there is a return
 */
int main(int a, char **b)
{
	DATA_t DATA[] = { DATA_0 };
	int ffile = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (ffile)
			: "r" (ffile));

	if (a == 2)
	{
		ffile = open(b[1], O_RDONLY);
		if (ffile == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_entry(b[0]);
				_entry(": 0: Error: Can't open ");
				_entry(b[1]);
				_pprtchar('\n');
				_pprtchar(MIINUSONE);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		DATA->rddfile = ffile;
	}
	listing_env(DATA);
	pp_stry(DATA);
	hloop(DATA, b);
	return (EXIT_SUCCESS);
}

