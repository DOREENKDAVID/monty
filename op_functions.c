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

	if (head == NULL)
	{
		line_number = line_number;
		fprintf(stderr, "L%u: can't pint, stack empty",
				line_number);
		exit(EXIT_FAILURE);

	}
	printf("%d\n", temp->n);
}

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

	if (temp == NULL)
	{
		line_number = line_number;
		fprintf(stderr, "L%u: can't pop an empty stack\n",
				line_number);
		free_stack();
		exit(EXIT_FAILURE);

	}
	delete_node_at_index(temp, 0);
}

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
	stack_t *new = NULL, *node_0 = NULL, *node_1 = NULL;
	int sum = 0;

	if (list_len(*head) < 2)
	{
		line_number = line_number;
		fprintf(stderr,
			"L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	node_0 = get_node_at_index(*head, 0);
	node_1 = get_node_at_index(*head, 1);

	sum = node_0->n + node_1->n;
	delete_node_at_index(head, 0);
	delete_node_at_index(head, 0);

	new =  add_node_beg(head, sum);
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed%u",
				line_number);
		free(new);
		exit(EXIT_FAILURE);		

	}
}

/**
 * m_nop - doesn’t do anything
 * @head: double pointer to node in linked list
 * @line_number:handls instructions based on their line numbers.
 * Return:nothing
 */

void m_nop(stack_t **head, unsigned int line_number)
{
	(void) = head;
	(void) = line_number;
}
