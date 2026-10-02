#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

char** tokenize_document(const char* text, int* token_count) {
    char* lower_text = strdup(text);
    for (int i = 0; lower_text[i]; i++) {
        lower_text[i] = tolower(lower_text[i]);
    }

    char** tokens = (char**)malloc(MAX_TOKENS * sizeof(char*));
    char* token = strtok(lower_text, " \t\n\r\f\v");
    *token_count = 0;

    while (token && *token_count < MAX_TOKENS) {
        tokens[*token_count] = (char*)malloc(MAX_TOKEN_LENGTH * sizeof(char));
        strncpy(tokens[*token_count], token, MAX_TOKEN_LENGTH - 1);
        tokens[*token_count][MAX_TOKEN_LENGTH - 1] = '\0';
        (*token_count)++;
        token = strtok(NULL, " \t\n\r\f\v");
    }

    free(lower_text);
    return tokens;
}

void main() {
    const char* doc = "Your sample document text goes here.";
    int token_count;
    char** tokens = tokenize_document(doc, &token_count);

    for (int i = 0; i < token_count; i++) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
}