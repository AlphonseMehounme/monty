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
	char *opcode;

	opcode = strtok(lineread, " ");
	value = strtok(NULL, " ");

	if (strcmp(opcode, "push") == 0)
	{
		if (value == NULL || !is_int(value))
		{
			fprintf(stderr, "Error: can't open file %s\n", file);
			return (EXIT_FAILURE);
		}
		push(stack, line);
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
	return (0);
}

/**
 * is_int - check if int
 * @str: value t check
 * Return: 1 or 0
 */

int is_int(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void free_stack(stack_t **stack)
{
	stack_t *current, *next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
