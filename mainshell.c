#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
* shell - the core of the shell
* @readline: the command ready for parsing and execution
* Return: the value returned from the execution
*/
int shell(char *readline)
{
char **command = NULL;
int status;
/* Parse the input line into an array of strings */
command = parse_the_line(readline);
/* Execute the command */
status = execute_the_line(command);
/* Free the memory used by the command array */
free(command);
}
{return status;
}

