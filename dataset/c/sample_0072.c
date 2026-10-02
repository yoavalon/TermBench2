#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TOKENS 10
#define MAX_TOKEN_LENGTH 50

char** process_text(const char* data) {
    char** tokens = (char**)malloc(MAX_TOKENS * sizeof(char*));
    for (int i = 0; i < MAX_TOKENS; i++) {
        tokens[i] = (char*)malloc(MAX_TOKEN_LENGTH * sizeof(char));
    }

    int token_count = 0;
    int length = strlen(data);
    int start = -1;
    for (int i = 0; i <= length; i++) {
        if (isalnum(data[i]) || data[i] == '_') {
            if (start == -1) {
                start = i;
            }
        } else {
            if (start != -1) {
                int token_length = i - start;
                if (token_length < MAX_TOKEN_LENGTH) {
                    strncpy(tokens[token_count], &data[start], token_length);
                    tokens[token_count][token_length] = '\0';
                    token_count++;
                }
                if (token_count == MAX_TOKENS) {
                    break;
                }
                start = -1;
            }
        }
    }

    return tokens;
}

void main() {
    const char* sample_text = "This is a sample text for tokenization. Let's see how it works.";
    char** result = process_text(sample_text);

    for (int i = 0; i < MAX_TOKENS; i++) {
        if (result[i][0] != '\0') {
            printf("%s\n", result[i]);
        }
    }

    for (int i = 0; i < MAX_TOKENS; i++) {
        free(result[i]);
    }
    free(result);
}