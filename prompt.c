#include "shell.h"

/**
 * prompt - creates a prompt to allow input of commands to be run in ths shell
 *
 * Return: the command string inputted by the user in the prompt
 */

char *prompt(void)
{
	char *buffer, *new_buffer;
	size_t len;
	
/*allocates memory for various the buffer strings*/
	buffer = malloc(sizeof(char) * 1024);
	new_buffer = malloc(sizeof(char) * 1024);

/*displays the prompt string in the form "[user]($)"*/
	dprintf(STDOUT_FILENO, "[%s]($) ", getenv("LOGNAME"));


/* reads a line from the standard input until a newline is encountered and stores it into the buffer variable*/
	getline(&buffer, &len, stdin);

/*strip the string of the '\n' character that is usually returned  from the getline function*/
	new_buffer = strtok(buffer, "\n");

	free(buffer);

/* the calling function is responsible for freeing the new_buffer string */
	return (new_buffer);
}
