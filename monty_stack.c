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

/**
*pint - prints the value at the top of the stack, followed by a new line
* @stack: pointer to linked list stack
 * @line: number of opcode line
*/
void pint(stack_t **stack, unsigned int line)
{
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->next->n);
}


/**
 * pop - remove element from top of a list
 *@stack: pointer to first node
 *@line: integer refering to number of bytecode line
 *Return: void
 */
void pop(stack_t **stack, unsigned int line)
{
	stack_t *node = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	*stack = node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(node);
}


/**
 * nop - does nothing.
 * @stack: Points to the top node of a stack linked list.
 * @line: The current line number of the bytecode file.
 */
void nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}
