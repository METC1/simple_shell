#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell_main.h"

/**
 * main - entry point to a simple shell, that can work in interactive mode
 * and in non-interactive mode
 * @argv: argument vector array
 * @argc: argument count
 * @envp: Environment variables imported
 * Return: 0 if success.
 */
int main(int argc, char *argv[], char *envp[])
{
	char sign = 0;
	char **array = NULL;
	char **envarray = NULL;
	char **my_path = NULL;

	if (argc == 1)
	{
		do {
			envarray = builtin_env(envp);
			my_path = srch_path(envarray);
			_putchar('$');
			_putchar('>');
			array = line_to_array(argv[0]);
			exec_command(array, envarray);
			/*process execute code*/
		} while (sign == 0);
	}
	else
	{
		envarray = builtin_env(envp);	
		exec_command(argv, envarray);
		
	}
	return (0);
}
