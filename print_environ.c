#include "main.h"

/**
 * print_environment - Prints the environment variables
 * to standard output
 *
 * Desription:
 * This function prints the environment variables
 * to the standard output (stdout).
 * It display each environment variable in the format
 * "VARIABLE=VALUE" on separate lines.
 *
 * Return: No return value.
 */
void print_environment(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
