#include "monty.h"

/**
 * is_digit - function checck if input is digit
 * @c: input to be checked
 * Return:1 if digit 0 if not
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);

}
