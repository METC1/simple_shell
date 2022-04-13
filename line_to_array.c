#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * line_to_array - transforms string typed in the command line by the user,
 * into an array of individual arguments. The string entered is assumed
 * to be less than 90 chars long & contain no more than 6 individual arguments
 * , the first position in the array is ocuppied by the supplied argument p.
 * Return: pointer to the array of arguments.
 *
 */
char **line_to_array()
{
	char *token, *buffer = NULL;
	size_t bufsize = 90;
	int i = 0, j = 0, glinerr;
	char **array = malloc(sizeof(char) * bufsize);

	if (array == NULL)
	{
	perror("Error in line_to_array:(malloc array)");
	exit(1);
	}
	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Error in line_to_array:(malloc buffer)");
		exit(1);
	}
	glinerr = getline(&buffer, &bufsize, stdin);
	if (glinerr == -1)
	{
	perror("Error in line_to_array: (getline)");
	exit(1);
	}
	for (j = 0; buffer[j] != '\0'; j++)
	{
		if (buffer[j] == '\n')
		buffer[j] = '\0';
	}
	token = strtok(buffer, " ");
	if (buffer == NULL)
	{
	perror("Error in line_to_array: strtok buffer");
	exit(1);
	}
	for (i = 0 ; token != NULL ; )
	{
		array[i++] = token;
		token = strtok(NULL, " ");
	}
	array[i] = NULL;
	return (array);
}
