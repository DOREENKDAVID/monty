#include "monty.h"

/**
 * m_add - adds the top two elements of the stack.
 * @head:double pointer to the linked list
 * @line_number:handls instructions based on their line numbers.
 * Return: added nodes
 * Description
 * Check if the dlinked list has at least two nodes
 * Get the first two nodes of the dlinked list
 * Calculate the sum of the values of the first two nodes
 * Delete the first two nodes from the dlinked list
 * Add a new node with the sum as its value at the beginning
 * Handle the case of memory allocation failure
 */

void m_add(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = NULL, *node_0 = NULL, *node_1 = NULL;
	int sum = 0;

	if (list_len(*head) < 2)
	{
		fprintf(stderr,
			"L%u: can't add, stack too short\n",
			line_number);
		fclose(global.fptr);
		free(global.line_ptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	node_0 = get_node_at_index(*head, 0);
	node_1 = get_node_at_index(*head, 1);

	sum = node_0->n + node_1->n;
	delete_node_at_index(head, 0);
	delete_node_at_index(head, 0);

	new_node =  add_node_beg(head, sum);
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed%u",
				line_number);
		free(new_node);
		exit(EXIT_FAILURE);

	}
}

