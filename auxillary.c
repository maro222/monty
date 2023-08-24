#include "monty.h"


/**
 *free_all - free all the memory
 *@stack: stack of the program
 *Return: nothing
 */
void free_all()
{
	if (glob_var.buffer)
		free(glob_var.buffer);
	if (glob_var.args)
		free(glob_var.args);
	if (glob_var.opcode)
		free(glob_var.opcode);
}

/**
 *free_stack - free the stack
 *@stack: stack
 *Return: nothing
 */

void free_stack(stack_t ** stack)
{
	stack_t *ptr =  (*stack);

	while (*stack)
	{
		(*stack) = (*stack)->next;
		free(ptr);
		ptr = (*stack);
	}
}


/**
 *isnumber - check if args has a number in string format
 *@str: string to check
 *Return: 1 0n success, 0 on failure
 */

int isnumber(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}
	return (1);
}

