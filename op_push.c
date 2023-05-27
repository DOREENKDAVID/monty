#include "monty.h"

/**
 * m_push - func adds a node at the beginning of list
 * @head: double pointer  to the node in the linked list
 * @line_number:handls instructions based on their line numbers.
 *
 * Return: new node
 * Description:
 * Check if the input is a valid number
 * Handle the case of invalid input or data
 * Converting the input to an integer
 * Add the node to the stack based on the flag value
 * Handle the case of memory allocation failure
 */

void m_push(stack_t **head, unsigned int line_number)
{
	int num, input = 0, flag = 0;
	stack_t *new_node = NULL;

	if (global.arg)
	{
		if (global.arg[0] == '-')
			input++;
		for (; global.arg[input] != '\0'; input++)
		{
			if (!is_digit(global.arg[input]))
			{
				flag = -1;
			}
	if (flag  == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n",
				line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
		}
	}
	num = atoi(global.arg);

	if (global.flag == 0)
		new_node = add_node_beg(head, num);
	else
	{	if (global.flag == 1)
		{
			 new_node = add_node_end(head, num);
		}
	}

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed%u",
				line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	
	}
}
