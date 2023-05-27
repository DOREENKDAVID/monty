#include "monty.h"


/**
* m_stack - sets the format of the data to a stack (LIFO)
* @head: double pointer to first element of the stack
* @line_number: tracts instruction line read
*
* Return: void
* Description
* Set the flag variable in the global_vars to zero,
* to  indicate that the linked list should act as a stack.
*/
void m_stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	global.flag = 0;
}
