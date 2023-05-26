#include "monty.h"

global_t global = {NULL, NULL, NULL, 0};

/**
 * main - main function for Monty interpreter
 * @argc: arguments count passed to the program
 * @argv: array of argument strings
 * Return: 0 on success and 1 on failure
 * description
 * check if the number of arguments passed is not equal to 2
 * open the file specified by argv[1] for reading
 * assign the file ptr to global_s.fptr
 * read each line from the file using getline
 * track the line number using global_s.num
 * line read is passed to the strtok func to tokenizes 
 * checks if the arg member of global_s is !NULL 
 * and the 1st character of arg is not comment
 * call monty_opfunc, passing the arg member of global_s
 * as the opcode argument
 *
 *
 */
int main(int argc, char *argv[])
{
	char *line_ptr;
	FILE *fptr;
	size_t size = 0;
	ssize_t input = 1;
	stack_t *head = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fptr = fopen(argv[1], "r");
	global.fptr = fptr;
	if (fptr == NULL)
	{
		fprintf(stderr,"Error: Can't open file%s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (input > 0)
	{
		line_ptr = NULL;
		input = getline(&line_ptr, &size, fptr);
		global.line_ptr = line_ptr;
		line_number++;

		if (input > 0)
		{
		execute_opcode(line_ptr, &head, line_number, fptr);
		}
		free(line_ptr);
	}
	free_stack(head);
	fclose(fptr);
	return (0);
}
