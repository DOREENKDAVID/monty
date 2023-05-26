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
	int num = 0, input = 0;
	stack_t *new_node = NULL;
	char *arg = strtok(NULL, "\n\t\r ");

	if (arg && arg[0] == '-')
		input++;
	while (arg && arg[input])
	{
		if (!is_digit(arg[input]))
		{
			input = -1;
			break;
		}
		input++;
	}
	if (arg == NULL || input  == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n",
				line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = atoi(arg);

	if (global.flag == 0)
		new_node = add_node_beg(head, num);
	else if (global.flag == 1)
		new_node = add_node_end(head, num);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed%u",
				line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}


/**
* m_pall - print all elements in the linked list
* @head: pointer to the nodes of the list
* @line_number:handls instructions based on their line numbers.
* Return: number of nodes
* Description:
* i is used as a counter for the loop,
* temp is a temporary pointer to traverse the stack.
* Traverse the stack and print the values
*
*/

void m_pall(stack_t **head, unsigned int line_number)
{
	int i;
	stack_t *temp = *head;

	line_number = line_number;

	for (i = 0; temp != NULL; i++)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

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
	stack_t *new_node = NULL, *temp = *head;
	int i = 0;

	if (list_len(*head) < 2)
	{
		fprintf(stderr,
			"L%d: can't swap, stack too short\n",
			line_number);
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
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}
