#include "monty.h"

/**
 * m_pint - prints the value at the top of the stack\n
 * @head: double pointr to linked list
 * @line_number:handls instructions based on their line numbers.
 * Return: top element
 * Description:
 * Check if the doubly linked list is empty
 * Print the value of the first node
 */

void m_pint(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	if (*head == NULL)
	{
		line_number = line_number;
		fprintf(stderr, "L%u: can't pint, stack empty",
				line_number);
		fclose(global.fptr);
		free(global.line_ptr);
		free_stack(*head);

		exit(EXIT_FAILURE);

	}
	printf("%d\n", temp->n);
}

