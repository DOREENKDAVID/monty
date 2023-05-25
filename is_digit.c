#include "monty.h"

/**
 * is_digit - function checck if input is digit
 * @c: input to be checked
 * Return:1 if digit 0 if not
 */
int is_digit(char c)
{
	unsigned int i = 0;

	if (c[0] == '-')
	i++;
	while (c[i])
	{
	if (c >= '0' && c <= '9')
		i++;
	else
		return (1);
	}
	return (0);
}
