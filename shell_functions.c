#include <stdio.h>
#include "shell_prot.h"

void print_prompt_a(void)
{
printf("MyC shell$ ");
}

int shell_execute(char *command)

{
int i = 0;

if (command == NULL)/* empty, no argument passed */
{
	return 1;
}
/* Search for built in functions, return executes them "STIL NOT IMPLEMENTED"
for (i = 0; i < "number of array builtin functions"; i++)
{
	if (strcmp(args[0], builtin_str[i]) == 0)
	{
		return (*builtin_func[i])(args);
	}
}*/


/*return exec_command(command);*//*NOT DECLARED OR IMPLEMENTED*/
return (i); /*temp just to use i*/
}
