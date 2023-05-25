#include "monty.h"

/**
* free_stack - free all elements in linked list
*
*/

void free_stack(void)
{
	stack_t *temp = NULL;
	
	while (global_s.head != NULL)
	{
		temp =  global_s.head->next);
		free(global_s.head);
		global_s.head = temp;
	}
	fclose(global_s.fptr);
	free(global_s.line_ptr);
}
