#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** tokenize_text(const char* text, int* token_count) {
    char* lower_text = strdup(text);
    for (int i = 0; lower_text[i]; i++) {
        lower_text[i] = tolower(lower_text[i]);
    }

    *token_count = 0;
    char** tokens = NULL;
    const char* delimiters = " \t\n\r\f\v";
    char* token = strtok(lower_text, delimiters);
    while (token) {
        tokens = realloc(tokens, (*token_count + 1) * sizeof(char*));
        tokens[*token_count] = strdup(token);
        (*token_count)++;
        token = strtok(NULL, delimiters);
    }
    free(lower_text);
    return tokens;
}

void analyze_tokens(char** tokens, int token_count) {
    while (1) {
        for (int i = 0; i < token_count; i++) {
            if (strncmp(tokens[i], "float", 5) == 0) {
                char* value = tokens[i] + 5;
                char* endptr;
                double float_value = strtod(value, &endptr);
                if (*endptr == '\0') {
                    printf("Parsed float: %f\n", float_value);
                } else {
                    printf("Invalid float: %s\n", value);
                }
            }
        }
        tokens = tokenize_text(" ".join(tokens), &token_count);
    }
}

void main() {
    const char* text_input = "The document contains float values like float3.14 and floatNaN.";
    int token_count;
    char** tokens = tokenize_text(text_input, &token_count);
    analyze_tokens(tokens, token_count);
}