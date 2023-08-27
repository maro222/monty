#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to linked list for monty stack
 * @line_number: number of line opcode occurs on
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *block;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	block = (*stack)->next->next;
	(*stack)->next->next = block->next;
	(*stack)->next->prev = block;
	if (block->next)
		block->next->prev = (*stack)->next;
	block->next = (*stack)->next;
	block->prev = *stack;
	(*stack)->next = block;
}
