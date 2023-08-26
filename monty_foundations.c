#include "monty.h"


/**
 *read_file - read the file and execute the statements in it
 *@file : the file
 *@stack: stack of program
 *Return: nothing
 */

void read_file(char *file, stack_t **stack)
{
	instruction_t mon;
	size_t initial_size = 0;

	glob_var.file = fopen(file, "r");
	if (glob_var.file == NULL)
	{
		fprintf(stderr, "Can't open file %s", file);
		exit(EXIT_FAILURE);
	}
	while ((getline(&glob_var.buffer, &initial_size, glob_var.file)) != -1)
	{
		prepare_opcode(glob_var.buffer, stack);
		glob_var.line_number++;

		if (prepare_func(&mon))
		{
			if (glob_var.opcode)
				mon.f(stack, glob_var.line_number);
		}
		else
		{
			printf("L%d: unknown instruction %s"
					, glob_var.line_number, mon.opcode);
			free_stack(stack);
			free_all();
			fclose(glob_var.file);
			exit(EXIT_FAILURE);
		}
		free_all();
	}
	free_stack(stack);
	free(glob_var.buffer);
	fclose(glob_var.file);
}


/**
 *prepare_opcode - handle the opcode from(trailing-leading-between_line)spaces
 *@line: the line to handle
 *@stack: stack of gprogram
 *Return: opcode on success, NULL on failure
 */

void prepare_opcode(char *line, stack_t **stack)
{
	char *token = NULL;

	token = strtok(line, " \t\n");
	if (token == NULL || token[0] == '#')
		return;

	glob_var.opcode = malloc(sizeof(char) * (strlen(token) + 1));
	if (!glob_var.opcode)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(stack);
		free_all();
		fclose(glob_var.file);
		exit(EXIT_FAILURE);
	}
	strcpy(glob_var.opcode, token);

	token = strtok(NULL, " \n");
	if (!token)
		return;
	glob_var.args = (char *)malloc(sizeof(char) * (strlen(token) + 1));
	if (!glob_var.args)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(stack);
		free_all();
		fclose(glob_var.file);
		exit(EXIT_FAILURE);
	}
	strcpy(glob_var.args, token);
}

/**
 *prepare_func - prepare the right opcode from line
 *@mon: pointer to monty instruction_t datatype
 *Return: 1 on success, 0 on failure
 */

int prepare_func(instruction_t *mon)
{
	int i;
	instruction_t cmp[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{NULL, NULL},
	};

	if (!glob_var.opcode)
		return (1);
	for (i = 0; cmp[i].opcode; i++)
	{
		if (_strcmp(glob_var.opcode, cmp[i].opcode) == 0)
		{
			mon->f = cmp[i].f;
			return (1);
		}
	}
	return (0);
}
