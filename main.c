#include "main.h"
/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *Return: integer
 */
int main(int argc, char **argv)
{
	char *command = NULL;
	char *prog_name = argv[0];
	int i;
	(void)argc;

	while (TRUE)
	{
		if (!prompt(&command))
			continue;
		argv = set_args(command);

		if (argv)
		{
			if (_str_cmp(argv[0], "env") == 0)
			{
				print_environment();
				for (i = 0; argv[i] != NULL; i++)
					free(argv[i]);
				free(argv);
				continue;
			}
			if (cmd_set_unset_env(argv))
				continue;
			if (cmd_change_directory(argv))
				continue;
			execmd(prog_name, argv);

			if (argv)
			{
				for (i = 0; argv[i] != NULL; i++)
				{
					if (argv[i])
						free(argv[i]);
				}
			}
			free(argv);
		}
	}
	free(command);
	return (0);
}
