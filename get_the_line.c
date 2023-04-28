#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
* get_the_line - reads a line of input from stdin
*
* Return: a pointer to the input string
*/
char *get_the_line(void)
{
ssize_t read_bytes;
char *input_buffer = NULL;
size_t buffer_size = 0;
read_bytes = getline(&input_buffer, &buffer_size, stdin);
if (input_buffer == NULL)
{
perror("Error while allocating buffer");
exit(EXIT_FAILURE);
}
if (read_bytes == -1)
{
free(input_buffer);
exit(EXIT_SUCCESS);
}
if (strcmp(input_buffer, "exit\n") == 0)
{
free(input_buffer);
exit(EXIT_SUCCESS);
}
return input_buffer;
}

