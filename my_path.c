#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell_main.h"

/**
 * srch_path - search the environment variables for path
 * @envarray: pointer array with system environment
 * Return: Pointer to the list of path elements
 */


char **srch_path(char **envarray)
{
int i, j;
char **my_path = NULL;
char path_raw[200];
char *token;

j = 0;
for (i = 0; envarray[i] != NULL; i++)
	{
	}
my_path = malloc(sizeof(char *) * (i + 1));
if (my_path == NULL)
	{
	perror("Error in srch_path: (malloc)");
	exit(1);
	}
for (i = 0; envarray[i] != NULL; i++)
	{
	if (envarray[i][0] == 'P' && envarray[i][1] == 'A' && envarray[i][2] == 'T'
	&& envarray[i][3] == 'H')
		{
		for (j = 0; envarray[i][j] != '\0'; j++)
		{
		path_raw[j] = envarray[i][j];
		}
		path_raw[j] = '\0';
		token = strtok(path_raw, "=");
		for (j = 0; token != NULL; j++)
		{
		token = strtok(NULL, ":");
		my_path[j] = token;
		}
		}
		}
	/*for (j = 0; j <= 7; j++)*/
	/* {*/
	/* printf("\nMy PATH:\n%s", my_path[j]);*/
	/* }*/
	return (my_path);
	}
