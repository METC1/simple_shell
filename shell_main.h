#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **line_to_array(char *p);
int _putchar(char c);
int exec_command(char **array);

#endif
