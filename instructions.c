#include "monty.h"

/**
 * initInstructions - Initializes the array of instructions.
 *
 * Return: Pointer to the allocated array of instructions.
 */
instruction_t *initInstructions(void)
{
    instruction_t *instructions = malloc(sizeof(instruction_t) * INSTRUCTION_NUMBER);

    if (instructions == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    instructions[0].opcode = "push";
    instructions[0].f = _push;

    instructions[1].opcode = "pall";
    instructions[1].f = _pall;
   
    instructions[2].opcode = "pall";
    instructions[2].f = _pint;
 
    instructions[3].opcode = "pall";
    instructions[3].f = _pop;

    return instructions;
}

/**
 * getInstructionByOpcode - Finds the instruction by its opcode.
 * @instructions: Pointer to the array of instructions.
 * @opcode: The opcode to search for.
 *
 * Return: Pointer to the instruction structure if found, otherwise NULL.
 */
instruction_t *getInstructionByOpcode(instruction_t *instructions, char *opcode)
{
    while (instructions != NULL && instructions->opcode != NULL)
    {
        if (strcmp(instructions->opcode, opcode) == 0)
        {
            return instructions;
        }
        instructions++;
    }
    return NULL;
}

