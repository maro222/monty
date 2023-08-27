#include "monty.h"

/**
 * _add -  adds the top two elements of the stack
 * *@stack: stack of our program
 *@line_number: line number of opcode
 *Return: nothing
 */

void _add(stack_t **stack, unsigned int line_number)
{
        int block;

        if (*stack == NULL || (*stack)->next == NULL)
        {
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
        }

        block = (*stack)->n;
        pop(stack, line_number);
        (*stack)->n += block;
}
