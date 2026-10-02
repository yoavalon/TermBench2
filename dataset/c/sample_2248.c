#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

char** tokenize(const char* text, int* token_count) {
    char** tokens = (char**)malloc(MAX_TOKENS * sizeof(char*));
    for (int i = 0; i < MAX_TOKENS; i++) {
        tokens[i] = (char*)malloc(MAX_TOKEN_LENGTH * sizeof(char));
    }

    const char* delimiters = " \t\n\r";
    char* token = strtok((char*)text, delimiters);
    *token_count = 0;

    while (token != NULL && *token_count < MAX_TOKENS) {
        int is_word = 1;
        for (int i = 0; token[i] != '\0'; i++) {
            if (!isalnum(token[i])) {
                is_word = 0;
                break;
            }
        }
        if (is_word) {
            strcpy(tokens[*token_count], token);
            (*token_count)++;
        }
        token = strtok(NULL, delimiters);
    }

    return tokens;
}

void process_tokens(char** tokens, int token_count) {
    while (1) {
        for (int i = 0; i < token_count; i++) {
            char* token = tokens[i];
            if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
                char* endptr;
                double value = strtod(token, &endptr);
                if (*endptr == '\0') {
                    if (value == (int)value) {
                        printf("%d\n", (int)value);
                    } else {
                        printf("%.10f\n", value);
                    }
                }
            }
        }
    }
}

int main() {
    const char* text = "The quick brown fox jumps over the lazy dog 123.456789";
    int token_count;
    char** tokens = tokenize(text, &token_count);
    process_tokens(tokens, token_count);

    // Free allocated memory
    for (int i = 0; i < MAX_TOKENS; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}