#include "monty.h"

/**
* m_pchar - print the element at the top of stack as a char
* @head: double pointer to first element of the stack
* @line_number: instuctions on line read
* Description:
* Check if the stack is empty
* If the stack is empty, print an error message
* Check if the value of the top element is within the
* valid ASCII range (0 to 127).
* If the value is within the valid range, print it as a char
* If the value is outside the valid range, print an error message
*
* Return: void
*/
void m_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = *head;

	if (new_node == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
				line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (new_node->n >= 0 && new_node->n <= 127)
	{
		putchar(new_node->n);
		putchar('\n');
	}
	else
	{
	fprintf(stderr, "L%d: can't pchar, value out of range\n",
			line_number);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
}
