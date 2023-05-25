#include "monty.h"

/**
 * op_push - func adds a node at the beginning of list
 * @head: double pointer  to the node in the linked list
 * @line_number:handls instructions based on their line numbers.
 *
 * Return: new node
 */

void op_push(stack_t **head, unsigned int line_number)
{
	int data = 0;
	stack_t *new_node = malloc(sizeof(stack_t));

	line_number = line_number;

	if (!new_node)
		return;
	if (global_struct->arg_list[1] && is_num(global_struct->arg_list[1][0]))
		data = my_atoi(global_struct->arg_list[1]);
	else
	{
		fprintf(stderr,
			"L%d: usage: push integer\n",
			global_struct->linenum);
		free(new_node);
		exit(EXIT_SUCCESS);
	}

	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*head != NULL)
	{
		(*head)->prev = new_node;
		new_node->next = *head;
	}
	*head = new_node;

}


/**
* op_pall - print all elements in the linked list
* @head: pointer to the nodes of the list
* @line_number:handls instructions based on their line numbers.
* Return: number of nodes
*/

void op_pall(stack_t **head, unsigned int line_number)
{
	int i;
	stack_t *temp = *head;

	line_number = line_number;

	for (i = 0; temp; i++)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * op_swap - swaps the top two elements of the stack.
 * @head: pointer to the nodes of the list
 * @line_number:handles instructions based on their line numbers.
 * Return: swaped  nodes
 */


void op_swap(stack_t **head, unsigned int line_number)
{
	stack_t *new = NULL, *temp = *head;
	int i = 0;

	if (list_len(*head) < 2)
	{
		line_number = line_number;
		fprintf(stderr,
			"L%d: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	temp = get_node_at_index(*head, 0);
	i = temp->n;
	delete_node_at_index(head, 0);
	new = insert_node_at_index(head, 1, i);
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
}
}
