#ifndef MONTY_MONTY_H
#define MONTY_MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 *struct Global - global var across the files
 *@file: the file to open
 *@line_number: the line number
 *@args: argument if there is
 *@buffer: buffer if the file
 *@opcode: opcode of the line of file
 *Description: global vaible across the files
 *to be used
 */

typedef struct Global
{
	FILE *file;
	char *buffer;
	unsigned int line_number;
	char *args;
	char *opcode;
} global;

extern global glob_var;

void read_file(char *file, stack_t **stack);
void prepare_opcode(char *line, stack_t **stack);
int prepare_func(instruction_t *mon);


int isnumber(char *str);
void free_all(void);
void free_stack(stack_t **stack);


void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line);
void pop(stack_t **stack, unsigned int line);
void nop(stack_t **stack, unsigned int line);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

#endif
