#include "monty.h"

/**
 *sub - The opcode sub subtracts the top element of the stack
 *      from the second top element of the stack.
 *@stack: stack of our program
 *@line_number: line number of opcode
 *Return: nothing
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_all();
		free_stack(stack);
		fclose(glob_var.file);
		exit(EXIT_FAILURE);
	}

	ptr = (*stack);
	ptr->next->n -= ptr->n;
	pop(stack, line_number);
}
