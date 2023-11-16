#include "monty.h"

/**
 * parse_instructions - parse and execute monty instruction
 * @stack: Piinter to the stack
 * @lineread: line contqining the instructions
 * @line: line number the file
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int parse_instructions(stack_t **stack, char *lineread, unsigned int line)
{
	char *opcode, *value;

	opcode = strtok(lineread, " ");
	value = strtok(NULL, " ");

	if (strcmp(opcode, "push") == 0)
	{
		if (value == NULL || !is_integer(value))
		{
			fprintf(stderr, "Error: can't open file %s\n", file);
			return (EXIT_FAILURE);
		}
		push(stack, atoi(value), line);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
		exit(EXIT_FAILURE);
	}
}
