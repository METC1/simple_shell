#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell_main.h"

/**
 * fix_my_path - checks and fixes my_path final / if not present
 * @my_path: pointer array with path directories
 * Return: NULL only fixes my_path
 */

void fix_my_path(char **my_path)
{
int i, j;

for (i = 0; my_path[i] != NULL; i++)
	{
	printf("create_my_path[%d]: %s\n", i, my_path[i]);
	}
for (i = 0; my_path[i] != NULL; i++)
	{
	/*printf("my_path[%d]: %s\n", i, my_path[i]);*/
	for (j = 0; my_path[i][j] != '\0'; j++)
		{
		}
	if (my_path[i][j] != '/')
		{
		my_path[i][j] = '/';
		my_path[i][j + 1] = '\0';
		}
	/*printf("Path[%d]: %s\n", i, my_path[i]);*/
	}
}
