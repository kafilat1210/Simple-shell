#include "main.h"

/**
 * execmd - Takes in a pointer to a pointer argv
 * @prog_name: Name of the program
 * @argv: An array of vectors
 * Return: Nothing
 */
int execmd(char *prog_name, char **argv)
{
	string command = NULL, actual_command =  NULL;
	pid_t child_pid;
	int status;

	if (argv)
	{
		command = argv[0];
		cmd_exit(command, argv);
		actual_command = get_location(command);

		if (actual_command == NULL)
		{
			if (!isatty(0))
			{
				printf("%s: 1: %s: not found", prog_name, command);
				exit(EXIT_FAILURE);
			}
			perror(prog_name);
			return (1);
		}
		else
		{
			child_pid = fork();
			if (child_pid == 0)
			{
				execve(actual_command, argv, environ);
			}
			else if (child_pid > 0)
			{
				wait(&status);
			}
			else
			{
				perror("fork error");
				return (1);
			}
			free(actual_command);
			return (WEXITSTATUS(status));
		}
	}
	return (0);
}
