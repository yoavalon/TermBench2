#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

char** tokenize_document(const char* text, int* token_count) {
    char** tokens = (char**)malloc(MAX_TOKENS * sizeof(char*));
    for (int i = 0; i < MAX_TOKENS; i++) {
        tokens[i] = (char*)malloc(MAX_TOKEN_LENGTH * sizeof(char));
    }

    const char* delimiters = " \t\n\r\f\v";
    const char* start = text;
    const char* end = text;
    int count = 0;

    while (*end != '\0') {
        if (strchr(delimiters, *end) == NULL) {
            start = end;
            while (*end != '\0' && strchr(delimiters, *end) == NULL) {
                end++;
            }
            strncpy(tokens[count], start, end - start);
            tokens[count][end - start] = '\0';
            count++;
        } else {
            end++;
        }
    }

    *token_count = count;
    return tokens;
}

void analyze_tokens(char** tokens, int token_count) {
    while (1) {
        for (int i = 0; i < token_count; i++) {
            char* token = tokens[i];
            char* end;
            double number = strtod(token, &end);
            if (*end == '\0') {
                printf("%f\n", number);
            } else {
                printf("%s\n", token);
            }
        }
    }
}

int main() {
    const char* text = "In floating point precision, 3.14159 is a notable number.";
    int token_count;
    char** tokens = tokenize_document(text, &token_count);
    analyze_tokens(tokens, token_count);

    // Free allocated memory
    for (int i = 0; i < MAX_TOKENS; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}