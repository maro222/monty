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

	if (!isnumber(glob_var.args) || !glob_var.args)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		free_all();
		fclose(glob_var.file);
		exit(EXIT_FAILURE);
	}

	node = (stack_t *) malloc(sizeof(stack_t));

	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		free_all();
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
 * @line_number: number of opcode line
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all();
		free_stack(stack);
		fclose(glob_var.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * pop - remove element from top of a list
 *@stack: pointer to first node
 *@line_number: integer refering to number of bytecode line
 *Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all();
		free_stack(stack);
		fclose(glob_var.file);
		exit(EXIT_FAILURE);
	}
	node = (*stack);
	(*stack) = (*stack)->next;
	free(node);
	node = NULL;
	(*stack)->prev = NULL;
}


/**
 * nop - does nothing.
 * @stack: Pointer to the top node of a stack linked list.
 * @line_number: current line number of the bytecode file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
