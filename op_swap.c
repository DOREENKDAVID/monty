#include "monty.h"

/**
 * m_swap - swaps the top two elements of the stack.
 * @head: pointer to the nodes of the list
 * @line_number:handles instructions based on their line numbers.
 * Return: swaped  nodes
 * Description
 * Check if the stack has at least two nodes
 * Swap the values of the first two nodes
 * assigns the value of 1st node (temp->n) to the variable i.
 * delete the first node from the stack.
 * insert a new node at the 2nd pos of stack, with the value i.
 * return a pointer to the newly inserted node.
 * Handle the case of memory allocation failure
 */


void m_swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head, *new_node = NULL;
	int i = 0;

	if (list_len(*head) < 2)
	{
		fprintf(stderr,
			"L%d: can't swap, stack too short\n",
			line_number);
		fclose(global.fptr);
		free(global.line_ptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = get_node_at_index(*head, 0);
	i = temp->n;
	delete_node_at_index(head, 0);
	new_node = add_node_at_index(head, 1, i);
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed%u",
				line_number);
		free(new_node);
		exit(EXIT_FAILURE);
	}
}
