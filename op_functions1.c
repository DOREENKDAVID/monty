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


