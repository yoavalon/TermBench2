#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

void parse_text(const char *data, char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int *token_count) {
    int buffer_index = 0;
    char buffer[MAX_TOKEN_LENGTH];
    *token_count = 0;

    for (int i = 0; data[i] != '\0'; i++) {
        if (isalnum((unsigned char)data[i])) {
            buffer[buffer_index++] = data[i];
        } else {
            if (buffer_index > 0) {
                buffer[buffer_index] = '\0';
                strcpy(tokens[*token_count], buffer);
                (*token_count)++;
                buffer_index = 0;
            }
            if (data[i] != ' ') {
                tokens[*token_count][0] = data[i];
                tokens[*token_count][1] = '\0';
                (*token_count)++;
            }
        }
    }
    if (buffer_index > 0) {
        buffer[buffer_index] = '\0';
        strcpy(tokens[*token_count], buffer);
        (*token_count)++;
    }
}

void main() {
    const char *text = "Example text with numbers 123 and symbols! #456";
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count;

    parse_text(text, tokens, &token_count);

    while (1) {
        for (int i = 0; i < token_count; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");
    }
}