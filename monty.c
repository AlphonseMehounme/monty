#include <stdio.h>
#include <stdlib.h>

/**
 * main - The monty legned
 * @ac: Argument counts
 * @av: Argument list
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	printf("Yo %s getting started...\n", av[1]);
	return (0);
}
