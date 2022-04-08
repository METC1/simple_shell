#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * line_to_array - transforms the string typed in the command line by the user,
 * into an array of individual arguments. The string the user enters is
 * assumed to be less than 90 chars long and to contain no more than 6
 * individual arguments, the first position in the array is ocuppied by the
 * supplied argument p.
 * @p: pointer that will be used as first element of the array.
 * Return: pointer to the array of arguments.
 */

char **line_to_array(char *p)
{
	char *buffer = NULL;
	size_t bufsize = 90;
	char *token;
	int i = 1;
	char **array = malloc(sizeof(char)* bufsize);

	buffer = malloc(bufsize * sizeof(char));
	/*Update error message and return in case that malloc fails*/
	if(buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	getline(&buffer, &bufsize, stdin);
	token = strtok(buffer, " ");
	array[0]= p;
	/*Insert error option that checks for error if buffer = NULL
	due to user failing to introduce valid commands at the comand line
	and, check if is neccesary to include error if strtok fails*/
	for(i = 1 ; token != NULL ; )
	{
			array[i++] = token;
			token = strtok(NULL, " ");
	}
	return(array);
	/*
	To understand what this function returns, it can be modified to print
	the elements of *array, each one followed by a new line:
	1. Update the function prototipe to: int (main)
	
	2. Before the getline line insert the following code:
	printf("Enter arguments: ");
	
	3. Replace the retun line with the following code:
	for (i = 0; i < 3; ++i)
	{
		printf("%s\n", array[i]);
	}
	return(0);
	*/
	
	/*
	NOTES: 
	1. In the event that an array with a non-estimated but exact number of
	elements is required; a counter function must be created and you must feed
	this function line_to_array. It has not been possible otherwise.
	2. This file has not been checked for Betty compliance.
	*/
}
