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
  pid_t child_pid, werr;
int status;

child_pid = fork ();
if (child_pid == -1)
{
	perror("Error in exec_command (fork)");
	return(1);
	
}

if (child_pid == 0)
{
	printf("Array[0]: %s\n", array[0]);
	printf("Array[1]: %s\n", array[1]);
	printf("Array[2]: %s\n", array[2]);
	if (execve(array[0], array, NULL) == -1) /*change variables for execve*/
	{
		perror("Error in exec_command: (execve)");
		return(1);
	}
	/* Child process replace with execve*/
	return(0);	
}
else
{
	werr = wait(&status);
	if (werr == -1)
	{
	perror ("Error in exec_command: (wait)");
	}
	return(0);
	/*Father process, wait*/
}
}
