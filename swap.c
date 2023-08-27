#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to linked list for monty stack
 * @line_number: number of line opcode occurs on
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *block;
	int temp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	block = (*stack);
	temp = block->n;
	block->n = block->next->n;
	block->next->n = temp;
}
