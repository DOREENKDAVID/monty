#include "monty.h"

/**
* m_pstr - print elements of stack as chars
* @head: pointer to first element of stack
* @line_number: instruction line read
* Description:
* Iterate over the elements of the stack ig != null
* Check if the value of the current node is within 0-127 ASCII
* If the value is within the valid range, print it as a char
* If the value is outside the valid range break
*
* Return: void
*/

void m_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = *head;

	(void)line_number;
	while (new_node != NULL)
	{
		if (new_node->n > 0 && new_node->n <= 127)
		{
			printf("%c", new_node->n);
			new_node = new_node->next;
		}
		else
			break;
	}
	printf("\n");
}
