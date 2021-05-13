#include "monty.h"

/**
 * get_func - checks for opcode functions and returns
 * them if they exist
 * @token: opcode
 * @line: line
 * Return: function or NULL
 */

void get_func((char *token)(stack_t **stack, unsigned int line_num))
{
	int i = 0;

	instruction_t ops[] = {
			{"push", push},
			{"pall", pall},
			{"pint", pint},
			/*{"pop", pop},
			{"swap", swap},
			{"add", add},
			{"nop", nop},*/
			{"NULL, NULL"}
	};
	
	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, token) == 0)
		{
			ops[i].f(stack, line_num);
			return;
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", line_num, token);
	exit(EXIT_FAILURE);
}
