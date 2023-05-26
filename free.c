#include "monty.h"

/**
* free_stack - free all elements in linked list
*
*/

void free_stack(stack_t *head)
{
	stack_t *temp = NULL;

	temp = head;
	
	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	fclose(global.fptr);
	free(global.line_ptr);
}
