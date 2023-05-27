#include "monty.h"


/**
* m_rotl - rotate the stack to the top
* @head: double pointer to first element of the stack
* @line_number: tracks instruction line read
*
* Return: void
* Description:
* Check if the stack is empty
* Get the first node
* Store the value of the first node.
* Delete the first node
* Add a new node at the end of the stack with data value
*
*/
void m_rotl(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	int data = 0;

	(void)line_number;
	if (*head == NULL)
		return;
	temp = get_node_at_index(*head, 0);
	data = temp->n;
	delete_node_at_index(head, 0);
	add_node_end(head, data);
}
