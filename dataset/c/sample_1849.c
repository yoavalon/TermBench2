#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

char* tokenize(const char* str) {
    static char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    static int token_index = 0;
    char* token = strtok((char*)str, " ");
    while (token != NULL) {
        strcpy(tokens[token_index++], token);
        token = strtok(NULL, " ");
    }
    return tokens;
}

int is_float(const char* str) {
    char* endptr;
    strtod(str, &endptr);
    return *endptr == '\0';
}

void parse_text(const char* data) {
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count = 0;
    char* token = tokenize(data);
    while (*token) {
        if (is_float(*token)) {
            printf("%f ", atof(*token));
        } else {
            printf("%s ", *token);
        }
        token++;
        token_count++;
    }
    printf("\n");
}

int main() {
    const char* text = "The quick brown fox jumps over 1.2 lazy dogs 3.4 times.";
    parse_text(text);
    return 0;
}