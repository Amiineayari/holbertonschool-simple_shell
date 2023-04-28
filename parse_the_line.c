#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
* parse_the_line - parses the line
* @buff: the buffer containing the input line
*
* Return: a vector of pointers to the parsed words
*/
char **parse_the_line(char *buff)
{
int i = 0;
char **whole_line = NULL;
char *word = NULL;
whole_line = malloc(sizeof(char *) * 1024);
word = strtok(buff, " \n\t");
whole_line[i] = word;
while (word != NULL)
{
i++;
word = strtok(NULL, " \n\t");
whole_line[i] = word;
}
return (whole_line);
}
