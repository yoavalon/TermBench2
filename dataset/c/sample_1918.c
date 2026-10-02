#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 50

char** parse_document(char* text) {
    char** tokens = (char**)malloc(MAX_TOKENS * sizeof(char*));
    char* token = strtok(text, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i] = (char*)malloc(MAX_TOKEN_LENGTH * sizeof(char));
        strcpy(tokens[i], token);
        token = strtok(NULL, " ");
        i++;
    }
    return tokens;
}

float* tokenize_and_convert(char** tokens, int* float_count) {
    float* float_tokens = (float*)malloc(MAX_TOKENS * sizeof(float));
    *float_count = 0;
    for (int i = 0; tokens[i] != NULL; i++) {
        char* end;
        float float_token = strtod(tokens[i], &end);
        if (*end == '\0') {
            float_tokens[*float_count] = float_token;
            (*float_count)++;
        }
    }
    return float_tokens;
}

int main() {
    char document[] = "The temperature is 23.5 degrees Celsius and the pressure is 1.013 atmospheres.";
    char** tokens = parse_document(document);
    int float_count;
    float* float_tokens = tokenize_and_convert(tokens, &float_count);

    for (int i = 0; i < float_count; i++) {
        printf("%f ", float_tokens[i]);
    }
    printf("\n");

    // Free allocated memory
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);
    free(float_tokens);

    return 0;
}