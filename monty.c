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
	char *file = av[1];
	size_t linereadsize;
	char *lineread = NULL;
	int line = 0;

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
		puts(lineread);
	}
	return (0);
}
