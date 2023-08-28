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
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	block = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = block->next;
	block->prev = NULL;
	(*stack)->prev = block;
	if (block->next)
		block->next->prev = *stack;
	block->next = *stack;
	(*stack) = (*stack)->prev;
}
