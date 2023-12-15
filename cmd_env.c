#include "main.h"

/**
 * cmd_env - Implements the env built-in command
 * @argv: Argument vector
 * Return: Returns an int value
 */
int cmd_env(char **argv)
{
	if (_str_cmp(argv[0], "env") == 0)
	{
		print_environment();
		return (1);
	}

	return (0);
}
