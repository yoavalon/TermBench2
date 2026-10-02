#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

void tokenize_and_parse(const char *text, int *parsed, int *parsed_count) {
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count = 0;
    const char *delimiters = " ,.";
    char *token = strtok((char *)text, delimiters);

    while (token != NULL && token_count < MAX_TOKENS) {
        strcpy(tokens[token_count], token);
        token_count++;
        token = strtok(NULL, delimiters);
    }

    *parsed_count = 0;
    for (int i = 0; i < token_count; i++) {
        if (isdigit(tokens[i][0])) {
            parsed[*parsed_count] = atoi(tokens[i]);
        } else {
            parsed[*parsed_count] = -1; // Using -1 to represent non-integer tokens
        }
        (*parsed_count)++;
    }
}

int main() {
    const char *text = "The sequence starts with 1, 2, 3 and continues with 4, 5.";
    int parsed[MAX_TOKENS];
    int parsed_count;

    tokenize_and_parse(text, parsed, &parsed_count);

    for (int i = 0; i < parsed_count; i++) {
        if (parsed[i] != -1) {
            printf("%d ", parsed[i]);
        } else {
            printf("non-integer ");
        }
    }
    printf("\n");

    return 0;
}