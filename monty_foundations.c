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

	allocateBuffer();

	glob_var.file = fopen(file, "r");
	if (glob_var.file == NULL)
	{
		fprintf(stderr, "Can't open file %s", file);
		exit(EXIT_FAILURE);
	}
	while ((fgets(glob_var.buffer, INT_MAX, glob_var.file)) != NULL)
	{
		prepare_opcode(glob_var.buffer, &mon, stack);
		glob_var.line_number++;

		if (prepare_func(&mon))
			mon.f(stack, glob_var.line_number);
		else
		{
			printf("L%d: unknown instruction %s"
					, glob_var.line_number, mon.opcode);
			free_stack(stack);
			free_all();
			if (glob_var.file)
				fclose(glob_var.file);
			exit(EXIT_FAILURE);
		}
		free_all();
		allocateBuffer();
	}
	free_stack(stack);
	free(glob_var.buffer);
}

/**
 *allocateBuffer - allocate memory for buffer
 *Return: nothing
 */
void allocateBuffer(void)
{
	glob_var.buffer = (char *)malloc(sizeof(char) * INT_MAX);

	if (!glob_var.buffer)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
}


/**
 *prepare_opcode - handle the opcode from(trailing-leading-between_line)spaces
 *@line: the line to handle
 *@mon: pointer of instryction_t dadt type
 *@stack: stack of gprogram
 *Return: opcode on success, NULL on failure
 */

void prepare_opcode(char *line, instruction_t *mon, stack_t **stack)
{
	char *token = NULL;

	if (!line)
		return;
	mon->opcode = strtok(line, " \n");
	if (mon->opcode == NULL || mon->opcode[0] == '#')
		return;

	glob_var.opcode = malloc(sizeof(char) * (strlen(mon->opcode) + 1));
	if (!glob_var.opcode)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(stack);
		free_all();
		if (glob_var.file)
			fclose(glob_var.file);
		exit(EXIT_FAILURE);
	}
	strcpy(glob_var.opcode, mon->opcode);

	token = strtok(NULL, " \n");
	if (!token)
		return;
	glob_var.args = (char *)malloc(sizeof(char) * (strlen(token) + 1));
	if (!glob_var.args)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(stack);
		free_all();
		if (glob_var.file)
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
		{NULL, NULL},
	};

	for (i = 0; cmp[i].opcode; i++)
	{
		if (strcmp(mon->opcode, cmp[i].opcode) == 0 && mon->opcode)
		{
			mon->f = cmp[i].f;
			return (1);
		}
	}
	return (0);
}
