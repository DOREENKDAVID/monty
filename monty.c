#include "monty.h"


/**
 * main - main function for Monty interpreter
 * @argc: arguments count in the program
 * @argv: argument index pointers
 * Return: 0 on success and 1 on failure
 */
int main(int argc, char *argv[])
{
	stack_t *temp = NULL;

	if (argc != 2)
	{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
	}
	temp = NULL;
	head = &temp;
	read_line(argv[1], head);
	free_all(head);
	free(temp);
	exit(EXIT_SUCCESS);
}
