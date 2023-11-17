#include "monty.h"

/**
 * my_strdup - my strdup function
 * @src: characters to duplicate
 * Return: caracter
 */
char *my_strdup(const char *src)
{
	size_t len = strlen(src) + 1;
	char *dest = malloc(len);

	if (dest == NULL)
		exit(EXIT_FAILURE);
	strcpy(dest, src);

	return (dest);
}

/**
 * get_instructions - allocate dyna;icqly instructions
 * Return: instructions
 */

instruction_t *get_instructions()
{
	instruction_t *instructions = malloc(3 * sizeof(instruction_t));

	if (instructions == NULL)
	{
		exit(EXIT_FAILURE);
	}

	instructions[0].opcode = my_strdup("push");
	instructions[0].f = push;
	instructions[1].opcode = my_strdup("pall");
	instructions[1].f = pall;
	instructions[2].opcode = NULL;
	instructions[2].f = NULL;

	return (instructions);
}

/**
 * free_instructions - free instructions
 * @instructions: instruction to free
 */

void free_instructions(instruction_t *instructions)
{
	free(instructions);
}

/**
 * find - find functions
 * @opcode: functions variables
 * Return: NULL if not found and the fnction struct pointer if fouund
 */

instruction_t *find(char *opcode, instruction_t *instructions)
{
	int i = 0;

	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return (&instructions[i]);
		i++;
	}

	return (NULL);
}
