#include "monty.h"
int store_var;
/**
 * main - opens monty interface
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 for success, 1 for failure
 */
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	unsigned int line_len = 0;
	ssize_t line_length = 0;
	size_t len = 0;
	char *buffer = NULL, *token = NULL, **all_tokens;
	stack_t *stack = NULL;
	int i, count = 0;

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
	while ((line_length = getline(&buffer, &len, file)) != -1)
	{
		line_len++;
		token = strtok(buffer, "\n\t ");
		all_tokens = malloc(sizeof(char *) * (line_length + 1));
		while (token != NULL)
		{
			printf("%s\n", token);
			all_tokens[i] = token;
			token = strtok(NULL, "\n\t ");
			i++;
		}
		if (all_tokens != NULL)
		{
			get_func(all_tokens, &stack, line_len);
		}
	}
	fclose(file);
	exit(EXIT_SUCCESS);
}
