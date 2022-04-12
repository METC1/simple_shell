#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell_main.h"

/**
 * builtin_env - copies the env ironment variables for
 * further use and assigns memmory to locate the new array
 * @env: pointer array with system environment
 * Return: Pointer to the new created memmory allocated environment.
 */


char **builtin_env(char **env)
{
int i;
char **envarray = NULL;

	for (i = 0; env[i] != NULL; i++)
	{
	}
	envarray = malloc(sizeof(char *) * (i + 1));
	if (envarray == NULL)
	{
		perror("Error in builtin_env: (malloc)");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
	{
		envarray[i] = env[i];

	}
	envarray[i] = NULL;
	return (envarray);

}
