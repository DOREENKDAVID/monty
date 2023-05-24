#include "monty.h"

/**
 * select_op_func - selects correct function for format
 * @choice: input opcode
 * @line_number:handls instructions based on their line numbers.
 * Return: pointer to the function
 */
void (*select_op_func(char *choice))(stack_t **head, unsigned int line_number)
{
	instruction_t instructions[] =
       {
		{"push", op_push};
		{"pall", op_pall};
		{"pint", op_pint};
		{"pop", op_pop};
		{"swap", op_swap};
		{"add", op_add};
		{"nop", op_nop};
		{NULL, NULL}
	};

	int i = 0;


	while (instructions[i].opcode)
	{
		if (strcmp(choice, instructions[i].opcode) == 0)
			break;
		i++;
	}

	return (instructions[i].f);
}
