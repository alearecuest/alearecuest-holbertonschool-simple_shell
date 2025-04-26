#include "shell.h"

/**
 * main - Entry point for the shell program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Exit status of shell
 */
int main(int argc, char **argv)
{
	int status;
	
	(void)argc;
	(void)argv;
	
	status = run_shell_loop();
	return (status);
}
