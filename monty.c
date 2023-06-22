#include "monty.h"
#include <string.h>
#define MAX_LINE_LENGTH 1024
#define MAX_LINE_WORDS 100
#define INSTRUCTION_NUMBER 10

char **tokens;

instruction_t* initInstructions() {
  instruction_t *instructions = malloc(sizeof(instruction_t) * INSTRUCTION_NUMBER);
  
  if(instructions == NULL) {
    	fprintf(stderr, "Error: malloc failed\n");
		  exit(EXIT_FAILURE);
  }

  instructions[0].opcode = "push";
  instructions[0].f = _push;

  instructions[1].opcode = "pall";
  instructions[1].f = _pall;

  return instructions;
}

instruction_t* getInstructionByOpcode(instruction_t* instructions, char* opcode) {
  while (instructions->opcode != NULL && instructions != NULL) {
    if (strcmp(instructions->opcode, opcode) == 0) {
      return instructions;
    }
    instructions++;
  }
  return NULL;
}

char** splitLine(const char* line, int* wordCount) {
    const char delimiter[] = " \t";
    const int maxWords = MAX_LINE_WORDS;
    char** words = malloc(maxWords * sizeof(char*));  
    char* copy = _stdup(line);
    char* token;
    int count = 0;

    if(words == NULL) {
	    fprintf(stderr, "Error: malloc failed\n");
		  exit(EXIT_FAILURE);
    }

    token = strtok(copy, delimiter);
    while (token != NULL) {
        words[count] = _stdup(token);

        if (words[count][strlen(words[count]) - 1] == '\n') {
          words[count][strlen(words[count]) - 1] = '\0';
        }
        count++;
        if (count == maxWords)
            break;
        token = strtok(NULL, delimiter);
    }

    *wordCount = count;
    free(copy);
    return words;
}


void doubleFree(char** words, int wordCount) {
    int i = 0;
    while (i < wordCount) {
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
