#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell_main.h"
/**
 * exec_command - executes a command with its arguments
 * @array: pointer array with arguments, first the command name
 * @argv0: the shell name
 * @envarray: the environment variables array
 * Return: int 0.
 */
int exec_command(char *argv0, char **array, char **envarray)
{
pid_t child_pid;
int status, i, j;

if (_strcmp(array[0], "exit") == 0)
	{
	exit(EXIT_SUCCESS);
	}
if (_strcmp(array[0], "env") == 0)
	{
	for (i = 0; envarray[i] != NULL; i++)
		;
	for (j = 0; j <= i - 1; j++)
		printf("%s\n", envarray[j]);
	return (0);
	}
child_pid = fork();
if (child_pid == -1)
	{
	perror("Error in exec_command (fork)");
	return (1);
	}
if (child_pid == 0)
	{
	if (execve(array[0], array, NULL) == -1) /*change variables for execve*/
		{
		perror(argv0);
		exit(EXIT_SUCCESS);
		}
	return (0);
	exit(EXIT_SUCCESS);
	}
else
	{
	if (wait(&status) == -1)
		{
		perror("Error in exec_command: (wait)");
		}
	return (0);
	}
}
