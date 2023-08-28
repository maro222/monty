#include "monty.h"

/**
 *swap - swaps the top two elements of the stack
 *@stack: pointer to linked list for monty stack
 *@line_number: number of line opcode occurs on
 *Return: nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_all();
		free_stack(stack);
		fclose(glob_var.file);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
