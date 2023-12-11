#include "shell.h"

int main (int argc, char **argv)
{
	char *command = NULL;
	(void)argc;

	while (1)
	{
			if (!show_prompt(&command))
				continue;
			printf("You typed: %s\n", command);
	argv = args_setter(command);
	printf("The First Argument is: %s\n", argv[0]);
	}

	free(command);
	return (0);
}
