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
	fclose(global_s.fptr);
	free(global_s.line_ptr);
}
