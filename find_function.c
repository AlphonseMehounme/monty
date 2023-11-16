#include "monty.h"

/**
 * find - find functions
 * @opcode: functions variables
 * Return: NULL if not found and the fnction struct pointer if fouund
 */

instruction_t *find(char *opcode)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	int i = 0;

	while (instruction[i].opcode)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return (&instructions[i]);
		i++;
	}

	return (NULL);
}
