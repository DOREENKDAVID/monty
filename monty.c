#include "monty.h"

stack_t **global_head_ptr

/**
 * main - main function for Monty interpreter
 * @argc: arguments count in the program
 * @argv: argument index pointers
 * Return: 0 on success and 1 on failure
 */
int main(int argc, char *argv[])
{
	FILE *fptr;
	stack_t *head = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t readline = 0;
	unsigned int line_number = 0;
	void (*op_func)(stack_t **head, unsigned int line_number) = NULL;
	(void)argc;

	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
		fprintf(stderr, "Error: Can't open file %s\n",
				argv[1]);
		exit(EXIT_FAILURE);

	while ((readline = getline(&line, &len, fptr)) != -1)
	{
		line_number++;

		remove_new_line(&line)

		global_struct = create_global_struct(line_number, line);
		op_func = select_op_func(global_struct->arg_list[0]);
		if (op_func == NULL)
		{
			free_all(head, line, fptr);
			free_global_struct(global_struct);
			fprintf(stderr, "Error: free failed\n")
			exit(1);
		}

		op_func(&head, global_struct->line_number);

		free_global_struct(global_struct);

	}
	free_all(head, line, fptr);

	exit(EXIT_SUCCESS);
}
