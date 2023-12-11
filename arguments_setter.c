#include "shell.h"

char **args_setter(char *command)
{
	char **command_copy = NULL, *token = NULL;
	const char *delim = "\n";
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
			argv[i] = malloc(strlen(token) + 1);
			strcpy(argv[i], token);
			token = strtok(NULL, delim);

	}
	argv[i] = NULL;
	free(command_copy);
	free(command);
	return (argv);
}
