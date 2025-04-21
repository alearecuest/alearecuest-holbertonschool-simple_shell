#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * read_line - Lee una linea de entrada standar
 * Return: ptr a linea
 */
char *read_line(void);

/**
 * execute_command - ejecuta comandos sin argumentos
 * @command: comando a ejecutar
 * Return: 1 para seguir en loop
 */
int execute_command(char *command);

/**
 * is_exit - verifica si es exit
 * @command: comando intorducido por el usuario
 * Return: 1 para exit, 0 otro caso
 */
int is_exit(char *command);

extern char **environ;

#endif /* SHELL_H */
