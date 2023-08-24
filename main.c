#include "monty.h"

global glob_var = {NULL, NULL, 0, NULL, NULL};

/**
 *main - main function
 *@argc: number of argumentsi
 *@argv: number of
 *
 *Return: 1 on succeess , 0 on failure
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	read_file(argv[1], &stack);
	return (0);
}
