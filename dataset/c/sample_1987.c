#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

void parse_document(const char *text, char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int *token_count) {
    char current_token[MAX_TOKEN_LENGTH];
    int current_token_index = 0;
    *token_count = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        char char_ = text[i];
        if (isalnum(char_) || strchr("_.-", char_)) {
            current_token[current_token_index++] = char_;
        } else {
            if (current_token_index > 0) {
                current_token[current_token_index] = '\0';
                strcpy(tokens[(*token_count)++], current_token);
                current_token_index = 0;
            }
            if (isspace(char_)) {
                continue;
            }
            tokens[(*token_count)++][0] = char_;
            tokens[(*token_count)][0] = '\0';
        }
    }
    if (current_token_index > 0) {
        current_token[current_token_index] = '\0';
        strcpy(tokens[(*token_count)++], current_token);
    }
}

void tokenize(const char *text, char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int *token_count) {
    parse_document(text, tokens, token_count);
}

void main() {
    const char *document = "Hello, world! 123.45 is a number.";
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count;

    tokenize(document, tokens, &token_count);

    for (int i = 0; i < token_count; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");
}