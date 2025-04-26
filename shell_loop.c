#include "shell.h"

/**
 * run_shell_loop - Main shell loop
 * Description: Reads input, parses it into commands and executes them
 * Return: Status code of the last command executed
 */
int run_shell_loop(void)
{
	char *input = NULL;
	char **args;
	size_t bufsize = 0;
	ssize_t chars_read;
	int status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		chars_read = getline(&input, &bufsize, stdin);
		if (chars_read == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(input);
			return (status);
		}
		args = tokenize_input(input);
		if (args && args[0])
		{
			status = execute_command(args);
		}
		free(args);
	}
	free(input);
	return (status);
}
