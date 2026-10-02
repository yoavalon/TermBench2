#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

char** tokenize(const char* text) {
    char** tokens = (char**)malloc(MAX_TOKENS * sizeof(char*));
    for (int i = 0; i < MAX_TOKENS; i++) {
        tokens[i] = (char*)malloc(MAX_TOKEN_LENGTH * sizeof(char));
    }

    int token_count = 0;
    const char* p = text;
    char buffer[MAX_TOKEN_LENGTH];
    int buffer_index = 0;

    while (*p) {
        if (isalnum(*p)) {
            buffer[buffer_index++] = *p;
        } else {
            if (buffer_index > 0) {
                buffer[buffer_index] = '\0';
                strcpy(tokens[token_count++], buffer);
                buffer_index = 0;
            }
        }
        if (token_count >= MAX_TOKENS) break;
        p++;
    }

    if (buffer_index > 0) {
        buffer[buffer_index] = '\0';
        strcpy(tokens[token_count++], buffer);
    }

    return tokens;
}

void main() {
    const char* text = "This is a sample text for parsing and tokenization.";
    char** tokens = tokenize(text);

    for (int i = 0; i < MAX_TOKENS && tokens[i][0] != '\0'; i++) {
        printf("%s\n", tokens[i]);
    }

    // Free allocated memory
    for (int i = 0; i < MAX_TOKENS; i++) {
        free(tokens[i]);
    }
    free(tokens);
}