#include "shell.h"

/**
 * get_env_variable - Gets value of an environment variable
 * @name: Name of the environment variable
 * Description: Searches the environment for the given variable
 * Return: Pointer to the variable value or NULL if not found
 */
char *get_env_variable(const char *name)
{
	char **env;
	size_t name_len;

	if (!name)
		return (NULL);
	name_len = strlen(name);
	for (env = environ; *env; env++)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (&(*env)[name_len + 1]);
		}
	}
	return (NULL);
}
/**
 * find_command_in_path - Finds a command in PATH
 * @command: Command name to search for
 * Description: Searches each directory in PATH for the specified command
 * Return: Full path to the command if found, NULL otherwise
 */
char *find_command_in_path(char *command)
{
	char *path = get_env_variable("PATH");
	char *path_copy, *token, *full_path;
	size_t command_len, dir_len;

	if (!path || !command)
		return (NULL);
	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);
	command_len = strlen(command);
	token = strtok(path_copy, ":");
	while (token)
	{
		dir_len = strlen(token);
		full_path = malloc(dir_len + command_len + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
