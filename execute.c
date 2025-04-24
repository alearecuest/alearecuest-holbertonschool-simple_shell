#include "shell.h"

/**
 * execute_command - Executes a command based on input arguments
 * @args: Array of command arguments
 * @input: Input string (for freeing in exit command)
 *
 * Description: Checks if the command is built-in (exit, env) and executes
 * accordingly, or passes it to external command handler
 * Return: None
 */
void execute_command(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		handle_env();
	}
	else
	{
		execute_external_command(args);
	}
}

/**
 * execute_external_command - Executes an external command
 * @args: Array of command arguments
 *
 * Description: Forks a child process to execute the command
 * either using the direct path or searching in PATH
 * Return: None
 */
void execute_external_command(char **args)
{
	pid_t pid;
	char *command_path = args[0];

	if (access(command_path, X_OK) != 0)
	{
		command_path = find_command_in_path(args[0]);
	}


	pid = fork();
	if (pid == 0)
	{
		if (!command_path || access(command_path, X_OK) != 0)
		{
			print_command_error(args[0]);
			exit(127);
		}

		if (execve(command_path, args, environ) == -1)
		{
			perror(command_path);
			exit(127);
		}
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("Fork error");
	}

	if (command_path != args[0])
		free(command_path);
}
