#include "monty.h"

/**
 * m_sub - subtracts the top element of the stack
 * from the second top element of the stack..
 * @head: double pointer to the node in linked list
 * @line_number:handles instructions based on their line numbers.
 * Return:newnode with the diffrence
 * Description:
 * Check if the doubly linked list has at least two nodes
 * Get the first two nodes of the doubly linked list
 * Calculat the diff of the values of the first two nodes
 * Delet the first two nodes from the doubly linked list
 * Add a new node with the sub as its value at the beginning
 * Handle the case of memory allocation failure
 *
 */


void m_sub(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = NULL, *node_0 = NULL, *node_1 = NULL;
	int sub = 0;

	if (list_len(*head) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
		line_number = line_number;
	}
	node_0 = get_node_at_index(*head, 0);
	node_1 = get_node_at_index(*head, 1);

	sub = node_0->n - node_1->n;
	delete_node_at_index(head, 0);
	delete_node_at_index(head, 0);

	new_node =  add_node_beg(head, sub);
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed%u",
				line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}
