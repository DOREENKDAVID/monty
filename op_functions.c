#include "monty.h"

/**
 * op_pint - prints the value at the top of the stack\n
 * @head: double pointr to linked list
 * @line_number:handls instructions based on their line numbers.
 * Return: top element
 */

void op_pint(stack_t **head, unsigned int line_number)
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
 * op_pop - removes the top element of the stack.
 * @head: double pointer to node in the linked list
 * @line_number:handls instructions based on their line numbers.
 * Return:poped element data
 */


void op_pop(stack_t **head, unsigned int line_number)
{
	stack_t **temp = head;

	if (temp == NULL)
	{
		line_number = line_number;
		fprintf(stderr, "L%u: can't pop an empty stack\n",
				line_number);
		exit(EXIT_FAILURE);

	}
	delete_node_at_index(temp, 0);
}

/**
 * op_add - adds the top two elements of the stack.
 * @head:double pointer to the linked list
 * @line_number:handls instructions based on their line numbers.
 * Return: added nodes
 */

void op_add(stack_t **head, unsigned int line_number)
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
		line_number = line_number;

	}
}

/**
 * op_nop - doesn’t do anything
 * @head: double pointer to node in linked list
 * @line_number:handls instructions based on their line numbers.
 * Return:nothing
 */

void op_nop(stack_t **head, unsigned int line_number)
{
	head = head;
	line_number = line_number;
}
