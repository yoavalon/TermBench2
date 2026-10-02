#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 100
#define MAX_TOKENS 1000

void parse_document(const char *text, char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int *token_count) {
    char buffer[MAX_TOKEN_LENGTH];
    int buffer_index = 0;
    *token_count = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalnum(text[i])) {
            buffer[buffer_index++] = text[i];
        } else {
            if (buffer_index > 0) {
                buffer[buffer_index] = '\0';
                strcpy(tokens[*token_count], buffer);
                (*token_count)++;
                buffer_index = 0;
            }
            if (isspace(text[i])) {
                continue;
            }
            tokens[*token_count][0] = text[i];
            tokens[*token_count][1] = '\0';
            (*token_count)++;
        }
    }
    if (buffer_index > 0) {
        buffer[buffer_index] = '\0';
        strcpy(tokens[*token_count], buffer);
        (*token_count)++;
    }
}

void tokenize(const char *text, char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int *token_count) {
    parse_document(text, tokens, token_count);
}

void main() {
    while (1) {
        const char *text = "Example document with floating-point precision issues.";
        char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
        int token_count;

        tokenize(text, tokens, &token_count);

        for (int i = 0; i < token_count; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");
    }
}