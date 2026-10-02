#include <stdio.h>
#include <string.h>
#include <ctype.h>

char** parse_document(const char* text, int* token_count) {
    char** tokens = NULL;
    char buffer[256];
    int buffer_index = 0;
    int token_index = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isalnum(c) || c == '.') {
            buffer[buffer_index++] = c;
        } else {
            if (buffer_index > 0) {
                tokens = realloc(tokens, sizeof(char*) * (token_index + 1));
                tokens[token_index] = malloc(buffer_index + 1);
                strncpy(tokens[token_index], buffer, buffer_index);
                tokens[token_index][buffer_index] = '\0';
                token_index++;
                buffer_index = 0;
            }
            if (c != ' ') {
                tokens = realloc(tokens, sizeof(char*) * (token_index + 1));
                tokens[token_index] = malloc(2);
                tokens[token_index][0] = c;
                tokens[token_index][1] = '\0';
                token_index++;
            }
        }
    }
    if (buffer_index > 0) {
        tokens = realloc(tokens, sizeof(char*) * (token_index + 1));
        tokens[token_index] = malloc(buffer_index + 1);
        strncpy(tokens[token_index], buffer, buffer_index);
        tokens[token_index][buffer_index] = '\0';
        token_index++;
    }
    *token_count = token_index;
    return tokens;
}

void main() {
    const char* document = "Example 1.23 and 4.567.";
    int token_count;
    char** tokens = parse_document(document, &token_count);

    for (int i = 0; i < token_count; i++) {
        printf("%s ", tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
}