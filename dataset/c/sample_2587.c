#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_TOKEN_LENGTH 20

void tokenize(const char *text, char tokens[MAX_WORDS][MAX_TOKEN_LENGTH], int *token_count) {
    *token_count = 0;
    char buffer[1000];
    strcpy(buffer, text);
    char *token = strtok(buffer, " ,!.");
    while (token != NULL) {
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }
        strcpy(tokens[*token_count], token);
        (*token_count)++;
        token = strtok(NULL, " ,!.");
    }
}

void vectorize(const char tokens[MAX_WORDS][MAX_TOKEN_LENGTH], int token_count, const char *vocab[], int vector[3]) {
    for (int i = 0; i < 3; i++) {
        vector[i] = 0;
    }
    for (int i = 0; i < token_count; i++) {
        if (strcmp(tokens[i], vocab[0]) == 0) {
            vector[0]++;
        } else if (strcmp(tokens[i], vocab[1]) == 0) {
            vector[1]++;
        } else if (strcmp(tokens[i], vocab[2]) == 0) {
            vector[2]++;
        }
    }
}

void process_text(const char *text, int vector[3]) {
    const char *vocab[] = {"hello", "world", "python"};
    char tokens[MAX_WORDS][MAX_TOKEN_LENGTH];
    int token_count;
    tokenize(text, tokens, &token_count);
    vectorize(tokens, token_count, vocab, vector);
}

int main() {
    const char *text = "Hello world, hello Python!";
    int result[3];
    process_text(text, result);
    printf("%d %d %d\n", result[0], result[1], result[2]);
    return 0;
}