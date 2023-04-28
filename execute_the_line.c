#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
/**
* sigint_handler - handles the SIGINT signal (Ctrl+C)
* @sig_num: the signal number
*/
void sigint_handler(int sig_num)
{
signal(SIGINT, sigint_handler);
printf("\n");
}
/**
* execute_the_line - executes a command with its arguments using execve
* @buuf: an array of strings representing the command and its arguments
*
* Return: the status of the execve call
*/
int execute_the_line(char *buuf[])
{
char *path = "/bin/";
int status = 0;
if (buuf[0][0] == '/')
{
execve(buuf[0], buuf, NULL);
}
else
{
char *full_path = malloc(strlen(path) + strlen(buuf[0]) + 1);
strcpy(full_path, path);
strcat(full_path, buuf[0]);
status = execve(full_path, buuf, NULL);
free(full_path);
}
if (status == -1)
{
printf("Error: execve failed\n");
}
return status;
}
/**
* main - the main function
*
* Return: 0 on success
*/
int main(void)
{
char *buuf[] = {"ls", "-l", NULL};
signal(SIGINT, sigint_handler);
execute_the_line(buuf);
return (0);
}  
