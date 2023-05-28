#include "monty.h"

/**
 * parse - func to retrieve the  func ptr based on the opcode
 * @head: double pointer to first node
 * @line_ptr: user input command to execute
 * @line_number:handls instructions based on their line numbers.
 * @fptr:pointer to monty file
 * Return: void
 */
int parse(char *line_ptr, stack_t **head, unsigned int line_number, FILE *fptr)
{
	instruction_t instructions[] = {
		{"push", m_push}, {"pall", m_pall}, {"pint", m_pint},
		{"pop", m_pop},	{"swap", m_swap}, {"add", m_add},
		{"nop", m_nop},	{"sub", m_sub},
		{"mul", m_mul},
		{"div", m_div},
		{"mod", m_mod},
		{"pchar", m_pchar},
		{"pstr", m_pstr},
		{"rotl", m_rotl},
		{"rotr", m_rotr},
		{"queue", m_queue},
		{"stack", m_stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op_code;

	op_code = strtok(line_ptr, " \n\t");
	if (op_code && op_code[0] == '#')
		return (0);
	global.arg = strtok(NULL, " \n\t");
	while (instructions[i].opcode && op_code)
	{
		if (strcmp(op_code, instructions[i].opcode) == 0)
		{
			instructions[i].f(head, line_number);
			return (0);
		}
		i++;
	}
	if (op_code && instructions[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n",
				line_number, op_code);
		fclose(fptr);
		free(line_ptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	return (1);
}
