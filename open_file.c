#include "monty.h"

/**
 * open_file - opens and reads monty files
 * @argv: args
 * Return: NULL
 */
void open_file(char *filename)
{
	FILE *file = fopen(filename, "r");
	size_t len = 0;
	ssize_t line_len = 0;
	char *buffer = NULL, *token = NULL;
	int line_num = 1;
	void (*fchk)(stack_t **stack, unsigned int line_number);

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (line_len = getline(&buffer, &len, file) != EOF)
	{
		if (line_len = -1)
			free(buffer);

		token = strtok(buffer, "\n\t ");
		
		if (token == NULL)
			line_num++;
			continue;

		fchk = get_func(token);

		if (fchk == NULL)
		{
			printf("L%d: unkown instruction %s\n", line_num, token);
			exit(EXIT_FAILURE);
		}
		fchk(stack, line_num);
		line_num++;
	}
	fclose(file);
	free(buffer);
}
