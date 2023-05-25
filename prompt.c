#include "monty.h"

/**
 * tokenizer - splits line
 * @choice: user input command to execute
 * @line_number:handls instructions based on their line numbers.
 * Return: void
 */
void tokenizer(stack_t **head,char *choice, unsigned int line_number)
{
	instruction_t instructions[] =
       {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL}
	};

	int i = 0;


	while (instructions[i].opcode)
	{
		if (strcmp(choice, instructions[i].opcode) == 0)
			break;
		i++;
	}

	instructions[i].f(head, line_number);
	return;

	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, choice);
	if (*head != NULL)
	{
	free(head);
	}
	exit(EXIT_FAILURE);

}
