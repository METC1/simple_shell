#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * exec_command - executes a command with its arguments
 * @array: pointer array with arguments for the command,
 * the first arguments is always the command name
 * Return: int 0.
 */


int exec_command(char **array)
{
  pid_t child_pid;
int status;

child_pid = fork ();
if (child_pid == -1)
{
	perror("Error in fork");
	return(1);
	
}

if (child_pid == 0)
{
	printf("%s\n", array[0]);
	printf("%s\n", array[1]);
	if (execve(array[0], array, NULL) == -1) /*change variables for execve*/
	{
		perror("Error:");
		return(1);
	}
	/* Child process replace with execve*/
	return(0);	
}
else
{
	wait(&status);
	return(0);
	/*Father process, wait*/
}
}
