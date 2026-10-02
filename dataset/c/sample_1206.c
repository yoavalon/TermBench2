#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 50
#define MAX_WORD_LENGTH 100

char** tokenize_text(const char* text, int* token_count) {
    char** tokens = (char**)malloc(MAX_TOKENS * sizeof(char*));
    if (tokens == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    char* text_copy = strdup(text);
    char* word = strtok(text_copy, " ");
    *token_count = 0;

    while (word != NULL && *token_count < MAX_TOKENS) {
        tokens[*token_count] = (char*)malloc((strlen(word) + 1) * sizeof(char));
        if (tokens[*token_count] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        strcpy(tokens[*token_count], word);
        (*token_count)++;
        word = strtok(NULL, " ");
    }

    free(text_copy);
    return tokens;
}

int main() {
    const char* text = "This is a sample text for tokenization in Python.";
    int token_count;
    char** result = tokenize_text(text, &token_count);

    for (int i = 0; i < token_count; i++) {
        printf("%s ", result[i]);
        free(result[i]);
    }
    free(result);

    return 0;
}