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
   
    instructions[2].opcode = "pint";
    instructions[2].f = _pint;
 
    instructions[3].opcode = "pop";
    instructions[3].f = _pop; 
        
    instructions[4].opcode = "swap";
    instructions[4].f = _swap;
    
    instructions[5].opcode = "add";
    instructions[5].f = _add;
    
    instructions[6].opcode = "nop";
    instructions[6].f = _nop;

    instructions[7].opcode = "sub";
    instructions[7].f = _sub;

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

