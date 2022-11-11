#include "shell.h"

/**
 * main - handles command execution for the shell
 *
 * Return: on failure (1)
 */

int main(int ac __attribute__((unused)), char *av[])
{
	
	char *rm_wsp, *pstr, *str_token, *av_token, *buff, *pthnstr;
/*	char clear_screen[] = "\e[1;1H\e[2J";*/
	int prompt_state, i;
	char **argvec, **envec;


/*prints the starting screen of the shell.*/
	welcome_screen();


/*dynamically allocates memory for various strings*/
	pstr = malloc(sizeof(char) * 1024);	
	rm_wsp = malloc(sizeof(char) * 2);	
	av_token = malloc(sizeof(char) * 20);
	str_token = malloc(sizeof(char) * strlen(pstr));
	buff = malloc(sizeof(char) * 1024);
	pthnstr = malloc(sizeof(char) * 1024);
	argvec = malloc(sizeof(char) * 1024);
	envec = malloc(sizeof(char) * 1024);


	prompt_state = 1;

/*starts up the prompt;*/
	pstr = prompt();


/*checks if the string is null, if it is, call the prompt again, till the return is not null.*/
	while(pstr == NULL)
	{
		pstr = prompt();
	}


/*loops through to find what command the user typed in at the prompt, and deliver the corresponding response.*/
	while (prompt_state)
	{

/*splits the string returned from the prompt function into seperate words, and store each word in the argvec array.*/
		str_token = strtok(pstr, " ");
	
		i = 0;

		while(str_token != NULL)
		{
			argvec[i] = str_token;

			str_token = strtok(NULL, " ");

			i++;
		}


/*stores the value of the first string in the argvec array to the copy variable.*/
	av_token = argvec[0];


/*if first string contains only whitespaces, set it == NULL*/
	rm_wsp = strtok(argvec[0], " ");
		

		/*exits simple shell.*/
		if (strcmp(av_token, "exit") == 0)
		{
			dprintf(STDOUT_FILENO, "\nexiting simple_shell ===============================\n\n");
			/*frees dynamically allocated memory before exiting shell.*/
			free(buff);
			free(argvec);
			free(pthnstr);
			free(envec);
			free(pstr);
			free(av_token);
			
			exit(EXIT_SUCCESS);
		}

		/*list files and directories*/
		else if (strcmp(av_token, "ls") == 0)
		{
			pthnstr = "/bin/ls";
			if (execve(pthnstr, argvec, envec) == -1)
			{
				perror("An error occured");
			}	
			pstr = prompt();
		}
			
		/*clears the current screen*/
	/*	else if (strcmp(av_token, "clear") == 0)
		{
			printf("%s\n",clear_screen);
			pstr = prompt();
		}
*/
		/*prints working directory*/
		else if (strcmp(av_token, "pwd") == 0)
		{
			getcwd(buff, 1024);
			dprintf(STDOUT_FILENO, "%s\n", buff);
			pstr = prompt();
		}

		/*calls the prompt again if no command was entered*/
		else if (strcmp(av_token, "\n") == 0 || rm_wsp == NULL)
		{
			pstr = prompt();
		}

		/*prints error message if command is not valid.*/
		else{
		dprintf(STDOUT_FILENO, "%s: 1: %s: not found\n", av[0], argvec[0]);
		pstr = prompt();
		}

	}

	return (1);
}
