#include "shell.h"

/**
 * is_exit - Verifica si el comando es "exit"
 * @command: Comando ingresado por el usuario
 * Return: 1 si es "exit", 0 si no
 */
int is_exit(char *command)
{
	return (strcmp(command, "exit") == 0);
}

