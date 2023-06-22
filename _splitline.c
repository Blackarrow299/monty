#include "monty.h"

char **splitLine(const char *line, int *wordCount) {
    const char delimiter[] = " \t";
    const int maxWords = MAX_LINE_WORDS;
    char **words = malloc(maxWords * sizeof(char *));
    char *copy = _stdup(line);
    char *token;
    int count = 0;

    if (words == NULL) {
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

