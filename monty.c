#include "monty.h"
global_struct_t *global_struct = NULL;

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
	ssize_t read = 0;
	unsigned int linenumber = 0;
	void (*opfunc)(stack_t **head, unsigned int linenumber) = NULL;
	(void)argc;

	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fptr)) != -1)
	{
		linenumber++;

		remove_new_line(&line)

		global_struct = create_global_struct(linenumber, line);
		opfunc = get_op_func(global_struct->arg_list[0]);
		if (opfunc == NULL)
		{
			free_all(head, line, fptr);
			free_global_struct(global_struct);
			fprintf(stderr, "Error: free failed\n")
			exit(1);
		}

		opfunc(&head, global_struct->linenum);

		free_global_struct(global_struct);

	}
	free_all(head, line, fptr);

	exit(EXIT_SUCCESS);
}
