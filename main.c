# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "shell_prot.h"
/* #include <errno.h>		is it necessary???*/

/**
 * main - main shell 
 * @argc: int argument count (number of arguments entered)
 * @argv: pointer argument vector (strings of arguments)
 * Return: int 0 if succes
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused))) /*not using this variables at the moment*/
{
char exit = 0;
char *command;
size_t command_max_size = 32;/* maximum command line size*/
int chars_read __attribute__((unused)) = 0;

command = malloc(command_max_size * sizeof(char));/*space to store the command and arguments entered*/
do  /* THE INFINITE LOOP, until exit = 1 (do loop so we always enter the first loop)*/
{
	print_prompt_a();
	chars_read = getline(&command, &command_max_size, stdin);/*reads line from stdin and stores text in *command */
	shell_execute(command);
}while (exit == 1);
return (0);
}
