#include "monty.h"

/**
 *read_line - read input
 *@n: args value
 *@head: pointer to first node
 *Return: void
 */
void read_line(char *n, stack_t **head)
{
	char *line_ptr = NULL, *user_cmd;
	unsigned int line_number = 0;
	size_t buf;
	fptr = fopen(n, "r");
	
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", n);
		exit(EXIT_FAILURE);
	}
	while (getline(&line_ptr, &buf, fptr) != -1)
	{
		line_number++;
		user_cmd = strtok(line_ptr, "\n\t\r ");
		if (user_cmd != NULL && user_cmd[0] != '#')
		{
			tokenizer(head, user_cmd, line_number);
		}
	}
	free(line_ptr);
	fclose(fptr);
	exit(EXIT_SUCCESS);
}
