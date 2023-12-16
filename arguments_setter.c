#include "main.h"
/**
 * set_args - Parse a command string into an array of arguments.
 * This function takes a command string and tokenizes it into an array
 * of arguments, splitting the string using space and newline characters
 * as delimiters. It also handles the special case where the command
 * is "env" by printing the environment and teturning NULL.
 *
 * @command: The command string to parse.
 * Return: An array of strings (arguments) terminated by a NULL pointer,
 * or NULL if the command is "env" (environment print).
 */
char **set_args(char *command)
{
	char *command_copy = NULL, *token = NULL;
	const char *delim = " \n;";
	int i, num_token = 0;
	char **argv = NULL;

	command_copy = strdup(command);
	token = strtok(command, delim);

	while (token != NULL)
	{
		num_token++;
		token = strtok(NULL, delim);
	}
	num_token++;
	argv = malloc(sizeof(char *) * num_token);
	token = strtok(command_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(_str_len(token) + 1);
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(command_copy);
	free(command);
	return (argv);
}
