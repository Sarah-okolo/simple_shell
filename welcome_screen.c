#include "shell.h"

/**
* welcome_screen - prints out a basic starting screen on first execution.
* It is only displayed if the shell in interactive mode.
*
* the shell in a new proccess.
*/

void welcome_screen(void)
{
		printf("\n\t==============================================\n");
		printf("\t                Simple_Shell\n");
		printf("\t----------------------------------------------\n");
		printf("\t     A lightweight UNIX command interpreter\n");
		printf("\t==============================================\n\n\n");
}
