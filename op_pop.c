#include "monty.h"

/**
 * m_pop - removes the top element of the stack.
 * @head: double pointer to node in the linked list
 * @line_number:handls instructions based on their line numbers.
 * Return:poped element data
 * Description
 * Check if the doubly linked list is empty
 * Delete the first node from the doubly linked list
 */


void m_pop(stack_t **head, unsigned int line_number)
{
	stack_t **temp = head;

	if (*temp == NULL)
	{
		line_number = line_number;
		fprintf(stderr, "L%u: can't pop an empty stack\n",
				line_number);
		fclose(global.fptr);
		free(global.line_ptr);
		free_stack(*head);
		exit(EXIT_FAILURE);

	}
	delete_node_at_index(temp, 0);

}
