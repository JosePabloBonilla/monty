#include "monty.h"

/**
 * get_func - checks for opcode functions and returns
 * them if they exist
 * @token: opcode
 * Return: function or NULL
 */

void (*get_func(char *token))(stack_t **stack, unsigned int line_num)
{
	size_t i = 0;

	instruction_t ops[] = {
			{"push", push},
			{"pall", pall},
			{"pint", pint},
			{"pop", pop},
			{"swap", swap},
			{"add", add},
			{"nop", nop},
			{"sub", sub},
			{"div", _div},
			{"mul", mul},
			{"mod", mod},
			{NULL, NULL}
	};

	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, token) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
