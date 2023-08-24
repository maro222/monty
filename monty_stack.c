#include "monty.h"

/**
 *push - push the elements in monty file
 *@stack: stack of the program
 *@line_number: line number of the file
 *
 *Return: nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (!isnumber(glob_var.args))
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		free_stack(stack);
		free_all();
		if (glob_var.file)
			fclose(glob_var.file);
		exit(EXIT_FAILURE);
	}

	node = (stack_t *) malloc(sizeof(stack_t));

	if (!node)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(stack);
		free_all();
		if (glob_var.file)
			fclose(glob_var.file);
		exit(EXIT_FAILURE);
	}
	node->n = atoi(glob_var.args);
	node->prev = NULL;
	node->next = (*stack);

	if (*stack)
	{
		(*stack)->prev = node;
	}
	(*stack) = node;
}


/**
 *pall - dispaly the monty stack
 *@stack: stack of the program
 *@line_number: line number of the opcode
 *
 *Return: nothing
 */

void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *ptr = *stack;

	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
