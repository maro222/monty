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
	stack_t *ptr = NULL;

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

/**
 *_div - The opcode div divides the second top element of the stack
 *       by the top element of the stack.
 *@stack: stack of our program
 *@line_number: line number of opcode
 *Return: nothing
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = NULL;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_all();
		free_stack(stack);
		fclose(glob_var.file);
		exit(EXIT_FAILURE);
	}

	ptr = (*stack);

	if (ptr->n == 0)
        {
                fprintf(stderr, "L%u: division by zero\n", line_number);
                free_all();
                free_stack(stack);
                fclose(glob_var.file);
                exit(EXIT_FAILURE);
        }

	ptr->next->n /= ptr->n;
	pop(stack, line_number);
}


void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = NULL;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_all();
		free_stack(stack);
		fclose(glob_var.file);
		exit(EXIT_FAILURE);
	}

	ptr = (*stack);
	ptr->next->n *= ptr->n;
	pop(stack, line_number);
}

/**
 *mod - The opcode mod computes the rest of the division
 *      of the second top element of the stack by the top element of the stack.
 *@stack: stack of our 7
 *
 *
 */ 

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = NULL;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_all();
		free_stack(stack);
		fclose(glob_var.file);
		exit(EXIT_FAILURE);
	}

	ptr = (*stack);

	if (ptr->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		free_stack(stack);
		fclose(glob_var.file);
		exit(EXIT_FAILURE);
	}

	ptr->next->n %= ptr->n;
	pop(stack, line_number);
}

