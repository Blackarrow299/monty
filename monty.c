#include "monty.h"
#include <string.h>

char **tokens;

/**
 * doubleFree - Frees the memory allocated for the array of words and each word.
 * @words: Pointer to the array of words.
 * @wordCount: Number of words in the array.
 */
void doubleFree(char **words, int wordCount)
{
    int i = 0;

    while (i < wordCount)
    {
        free(words[i]);
        i++;
    }
    free(words);
}

int main(int argc, char *argv[]) {
    
    FILE *file;
    char *filename;
    char line[MAX_LINE_LENGTH];
    unsigned int line_number = 1;
    instruction_t *instructions = initInstructions();
    stack_t *stack = NULL;

    if (argc != 2) {
      fprintf(stderr, "USAGE: monty file\n");
      exit(EXIT_FAILURE);   
    }

    filename = argv[1];
    file = fopen(filename, "r");

    if (file == NULL) {
      fprintf(stderr, "Error: Can't open file %s\n", filename);
      exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        int wordsCount;
        char *opcode;
        instruction_t *instruction;
        tokens = splitLine(line, &wordsCount);
        if(wordsCount > 0) {
          opcode = tokens[0];
          instruction = getInstructionByOpcode(instructions, opcode);
          if(instruction == NULL) {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
          }else{
            instruction->f(&stack , line_number); 
          }
        }
      
        line_number++; 
        doubleFree(tokens, wordsCount);
    }
 
    _freestack(&stack); 
    free(instructions);
    fclose(file);

    exit(EXIT_SUCCESS);
}

