#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * main - The monty legned
 * @ac: Argument counts
 * @av: Argument list
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	FILE *fp;
	size_t linereadsize;
	char *lineread = NULL;
	unsigned int line = 0;
	char *file = av[1];
	stack_t *stack;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(file, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while (getline(&lineread, &linereadsize, fp) != -1)
	{
		line++;
		if (parse_instructions(&stack, lineread, line, file) == EXIT_FAILURE)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line, lineread);
			free(lineread);
			fclose(fp);
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}
	}
	free(lineread);
	fclose(fp);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
