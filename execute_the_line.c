#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include <signal.h>

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
  
