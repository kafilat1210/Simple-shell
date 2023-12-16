#include "main.h"
/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *Return: integer
 */
int main(int argc, char **argv)
{
	string command = NULL, prog_name = NULL;
	int i, status;

	(void)argc;
	prog_name = argv[0];

	while (TRUE)
	{
		if (!prompt(&command))
			continue;
		argv = set_args(command);
		if (argv)
		{
			if (cmd_set_unset_env(argv))
				continue;
			if (cmd_change_directory(argv))
				continue;
			status = execmd(prog_name, argv);
			if (status != 0)
				continue;
			if (argv)
			{
				for (i = 0; argv[i] != NULL; i++)
				{
					if (argv[i])
					{
						free(argv[i]);
					}
				}
				free(argv);
			}
		}
	}
	free(command);
	return (0);
}
