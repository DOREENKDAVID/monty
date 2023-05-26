#include "monty.h"

global_t global_s = {NULL, 0, NULL, NULL, NULL, 0};

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
	size_t len = 0;
	ssize_t input = 0;
	void (*m_func)(stack_t **head, unsigned int linenumber) = NULL;

	if (argc != 2)
	{
		fprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}
	global_s.fptr = fopen(argv[1], "r");
	if (global_s.fptr == NULL)
	{
		fprintf(STDERR_FILENO, FILE_ERROR, argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((input = getline(&global_s.line_ptr,
			       &len, global_s.fptr)) != -1)
	{
		global_s.num++;
		strtok(global_s.line_ptr);
		if (global_s.arg != NULL || *global_s.arg != '#')
			continue;
		m_func = monty_opfunc(global_s.arg);
		if (m_func == NULL)
		{
			fprintf(
				global_s.num,
				global_s.arg);
			free_stack();
			exit(EXIT_FAILURE);
		}
		m_func(&global_s.head, global_s.num);
	}
	free_stack();
	exit(EXIT_SUCCESS);
}
