# Proyect *SHELL*


### NAME
**$heloco$h** - A simple shell written in C


### SYNOPSIS

```text
#include "shell.h"


int main(void);
```


### DESCRIPTION

The **_`$helocosh`_** shell is a command interpreter that allows the execution of internal and external commands. It provides basic functionalities such as command execution, environment variable handling, and shell exit.

#### Internal commands

**_`exit`_** Terminates the shell execution.
**_`env`_** Prints all environment variables.

### **Command Execution**

The shell can execute both internal and external commands. If the command is not recognized as internal, it will be searched in the directories specified in the PATH environment variable.

### Functions

#### _builtins.c_

```text
void handle_exit(char **args, char *input)

- **_Description_**: Handles the exit command for the shell.
- **_Parameters_**: args -> Array of command arguments, input -> Input string to be freed.
- **_Return Value_**: None (terminates the process).
```

```text
void handle_env(void)

- **_Description_**: Prints all environment variables.
- **_Parameters_**: None.
- **_Return Value_**: None.
```

#### _errors.c_

void print_command_error(const char *cmd)

- **_Description_**: Prints an error message for the command not found.
- **_Parameters_**: cmd -> The command that was not found.
- **_Return Value_**: None.
```

#### _execute.c_

```text
void execute_command(char **args, char *input)
```

- **_Description_**: Executes a command based on input arguments.
- **_Parameters_**: args -> Array of command arguments, input -> Input string (for freeing in exit command).
- **_Return Value_**: None.
```

```text
void execute_external_command(char **args)
```

- **_Description_**: Executes an external command.
- **_Parameters_**: args -> Array of command arguments.
- **_Return Value_**: None.

```

#### _input.c_

```text
char **tokenize_input(char *input)
```

- **_Description_**: Splits the input string into tokens.
- **_Parameters_**: input -> The input string to tokenize.
- **_Return Value_**: Array of string tokens, or NULL on failure.

```

#### _path.c_

```text
char *get_env_variable(const char *name)
```

- **_Description_**: Gets the value of an environment variable.
- **_Parameters_**: name -> Name of the environment variable to retrieve.
- **_Return Value_**: Pointer to the value string, or NULL if not found.

```

```text
char *find_command_in_path(char *command)
```

- **_Description_**: Locates a command in the PATH environment variable.
- **_Parameters_**: command -> Command name to search for.
- **_Return Value_**: Full path to the command if found, NULL otherwise.

```

#### _promt.c_

```text
void print_prompt(void)
```

- **_Description_**: Displays the shell prompt.
- **_Parameters_**: None.
- **_Return Value_**: None.
```

#### _shell.c_

```text
int main(void)
```

- **_Description_**: Entry point for the shell program.
- **_Parameters_**: None.
- **_Return Value_**: 0 on success.
```

### RETURN VALUE

The **_`$heloco$h_** shell returns the number of characters printed (excluding the NULL byte used to end output to strings). If the format argument is NULL or if an invalid specifier is provided, the function returns -1.

### EXAMPLE

```text
#include "shell.h"

int main(void)
{
    char *input = "env";
    char **args = tokenize_input(input);
    execute_command(args, input);
    return (0);
}

```


### MORE EXAMPLES

$hsh: env
PATH=/usr/local/bin:/usr/bin:/bin
HOME=/home/user
...

$hsh: exit


| **_CASE_** | **_OUTPUT_** |
| ------------- |:-------------:|
| `$heloco$h: env` | **PATH=/usr/local/bin:/usr/bin:/bin** |
| | **HOME=/home/user** |
| |**SHELL=/bin/bash** |
| `$heloco$h: exit` | **finish th execution** |
| `$heloco$h: ls` | **README.md  buitlins.c  errors.c  execute.c  hsh  input.c  path.c  prompt.c  shell.c  shell.h  shell_loop.c** |
| `$heloco$h: pwd` | **/root/holbertonschool-simple_shell** |
| `$heloco$h: echo Hello, World!` | **Hello, World!** |
| `$heloco$h: unknown_command` | **./hsh: 1: unknown_command: not found** |
| `$heloco$h: mkdir prueba` | **Create file prueba** |
| `$heloco$h: rmdir prueba` | **Remove file prueba** |



### ERROR HANDLING

The **_`$heloco$h`_** The hsh shell handles errors gracefully. If an invalid format specifier is encountered, the function will return -1 and print an error message to stderr.


### LIMITATIONS
The current implementation of the **_`$heloco$h`_** shell does not support the following:

- Flag characters
- Field width
- Precision
- Length modifiers


### TESTING
To test the **_`$heloco$h`_** shell, compile your code using the following command:

```text
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Run the executable to see the output:

```text
$ ./hsh
```


==================================================================================

### AUTHOR

_Written by Pérez, Pablo & Arévalo, Alejandro_

==================================================================================
