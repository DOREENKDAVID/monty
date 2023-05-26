#include "monty.h"

/**
 * monty_opcode - to retrieve the  func ptr based on the opcode
 * @head: double pointer to first node
 * @choice: user input command to execute
 * @line_number:handls instructions based on their line numbers.
 * Return: void
 * Description:
 * Array of instruction_t structs defining opcode-function pairs
 * End of the array
 * loop through the array until a match for the specified opcode 
 * compares the opcode to opcode member of current instruction_t str
 * returns the function pointer instructions[i].f
 *
 */
void monty_opcode(stack_t **head, char *choice, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{"sub", m_sub},
		{"mul", m_mul},
		{"div", m_div},
		{"mod", m_mod},
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
