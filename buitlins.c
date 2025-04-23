#include "shell.h"

/**
 * handle_exit - Handles the exit command for the shell
 * @args: Array of command arguments
 * @input: Input string to be freed
 *
 * Description: Frees allocated memory and exits the shell
 * Return: None (exits process)
 */
void handle_exit(char **args, char *input)
{
	if (args)
		free(args);
	if (input)
		free(input);
	exit(0);
}

/**
 * handle_env - Prints all environment variables
 *
 * Description: Iterates through the environ array and prints
 *              each environment variable
 * Return: None
 */
void handle_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
