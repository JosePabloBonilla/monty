#include "monty.h"
/**
 * main - opens monty interface
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 for success, 1 for failure
 */
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	unsigned int line_len = 1;
	size_t len = 0;
	char *buffer = NULL, *token = NULL, *delim = "\n\t ";
	stack_t *stack = NULL;
	instruction_t op;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &len, file) != -1)
	{
		line_len++;
		token = strtok(buffer, delim);
		store_var = strtok(NULL, delim);

		if (token != NULL)
			op.f = get_func(token);

		if (op.f == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_len, token);
			exit(EXIT_FAILURE);
		}
		op.f(&stack, line_len);
	}
	fclose(file);
	exit(EXIT_SUCCESS);
}
