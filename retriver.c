#include "monty.h"

/**
 * retrive_ops - retrives correct opcode
 * @ops: opcode passed
 * Return: pointer
 */
void (*retrive_ops(char *ops))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"queue", op_queue},
		{"stack", op_stack},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"mul", op_multiply},
		{"div", op_divide},
		{"mod", op_mode},
		{"pchar", op_printchar},
		{"pstr", op_printstr},
		{"rotl", op_rotate},
		{"rotr", op_reverse},
		{NULL, NULL}
	};
	int a;

	for (a = 0; instruct[a].opcode; a++)
	{
		if (my_compstr(instruct[a].opcode, ops) == 0)
			break;
	}

	return (instruct[a].f);
}
