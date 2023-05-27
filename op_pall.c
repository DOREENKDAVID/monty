#include "monty.h"

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

	(void)line_number;

	for (i = 0; temp != NULL; i++)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
