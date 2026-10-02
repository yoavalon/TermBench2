#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_TOKEN_LENGTH 100

void tokenize(char *text, char tokens[MAX_WORDS][MAX_TOKEN_LENGTH], int *token_count) {
    char *token = strtok(text, " ");
    *token_count = 0;
    while (token != NULL) {
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }
        strcpy(tokens[*token_count], token);
        (*token_count)++;
        token = strtok(NULL, " ");
    }
}

void vectorize(char tokens[MAX_WORDS][MAX_TOKEN_LENGTH], int token_count, char *vocab[MAX_WORDS], int vocab_count, int vector[MAX_WORDS]) {
    for (int i = 0; i < vocab_count; i++) {
        vector[i] = 0;
    }
    for (int i = 0; i < token_count; i++) {
        for (int j = 0; j < vocab_count; j++) {
            if (strcmp(tokens[i], vocab[j]) == 0) {
                vector[j]++;
                break;
            }
        }
    }
}

int main() {
    char text[] = "hello world hello";
    char vocab[MAX_WORDS][MAX_TOKEN_LENGTH] = {"hello", "world"};
    int vocab_count = 2;
    char tokens[MAX_WORDS][MAX_TOKEN_LENGTH];
    int token_count;
    int vector[MAX_WORDS];

    tokenize(text, tokens, &token_count);
    vectorize(tokens, token_count, vocab, vocab_count, vector);

    for (int i = 0; i < vocab_count; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    return 0;
}