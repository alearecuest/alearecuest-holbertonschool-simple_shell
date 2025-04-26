#include "shell.h"
/**
 * execute_command - Executes a command based on input arguments
 * @args: Array of command arguments
 * Description: Checks if the command is built-in
 * Return: Status code of command execution
 */
int execute_command(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		handle_exit();
		return (0);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		handle_env();
		return (0);
	}
	else
	{
		return (execute_external_command(args));
	}
}
/**
 * execute_external_command - Executes an external command
 * @args: Array of command arguments
 * Description: Forks a child process to execute the command
 * Return: Status code of command execution
 */
int execute_external_command(char **args)
{
	pid_t pid;
	int status;
	char *command_path = args[0];
	if (access(command_path, X_OK) != 0)
	{
		command_path = find_command_in_path(args[0]);
		if (!command_path || access(command_path, X_OK) != 0)
		{
			print_command_error(args[0]);
			return (127);
		}
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(command_path, args, environ) == -1)
		{
			perror(command_path);
			exit(127);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (command_path != args[0])
			free(command_path);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		return (2);
	}
	else
	{
		perror("Fork error");
		return (1);
	}
	return (0);
}
