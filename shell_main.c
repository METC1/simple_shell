#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell_main.h"

/**
 * main - entry point to a simple shell, that can work in interactive mode
 * and in non-interactive mode
 * @argv: argument vector array
 * @argc: argument count
 * Return: 0 if success.
 */
int main(int argc, char *argv[])
{
	char sign = 0;
	char *array[6];
	int i;

	if (argc == 1)
	{
		do
		{
			_putchar('$');
			_putchar(' ');
			*array = line_to_array(argv[0]);
			for (i = 0; i < 7; i++)
			{
			printf("%s\n", array[i]);
			}
			exec_command(array);
			/*process execute code*/
		}while (sign == 0);
	}
	else
	{
		/*array[] = argv[];*/
		exec_command(array);
		/*process execute code*/
	}
	return (0);
}
