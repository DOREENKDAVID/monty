#include "monty.h"

/**
 * op_sub - subtracts the top element of the stack
 * from the second top element of the stack..
 * @head: double pointer to the node in linked list
 * @line_number:handles instructions based on their line numbers.
 * Return:node diffrence
 */


void op_sub(stack_t **head, unsigned int line_number)
{
	stack_t *new = NULL, *node_0 = NULL, *node_1 = NULL;
	int sum = 0;

	if (list_len(*head) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
		line_number = line_number;
	}
	node_0 = get_node_at_index(*head, 0);
	node_1 = get_node_at_index(*head, 1);

	sum = node_0->n - node_1->n;
	delete_node_at_index(head, 0);
	delete_node_at_index(head, 0);

	new =  add_node_beg(head, sum);
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed%u",
				line_number);
		exit(EXIT_FAILURE);
		line_number = line_number;
	}
}

/**
* op_div - divides the second top element o
* stack by the top element of the stack.
* @head: double pointer to the node in linked list
* @line_number:handles instructions based on their line numbers.
* Return: 1 on success 0 on failure
*/

void op_div(stack_t **head, unsigned int line_number)
{
	stack_t *new = NULL, *node_0 = NULL, *node_1 = NULL;
	int sum = 0;

	if (list_len(*head) < 2)
	{
		line_number = line_number;
		fprintf(stderr, "L%u: can't div, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);

	}
	if (node_0->n == 0)
	{
		line_number = line_number;
		fprintf(stderr, "L%u: division by zero\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	node_0 = get_node_at_index(*head, 0);
	node_1 = get_node_at_index(*head, 1);

	sum = node_0->n / node_1->n;
	delete_node_at_index(head, 0);
	delete_node_at_index(head, 0);

	new =  add_node_beg(head, sum);
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed%u",
				line_number);
		exit(EXIT_FAILURE);

		line_number = line_number;
	}
}
