#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_WORD_LENGTH 50

void tokenize(char *text, char tokens[MAX_TOKENS][MAX_WORD_LENGTH], int *token_count) {
    int i = 0, j = 0, k = 0;
    *token_count = 0;
    while (text[i] != '\0') {
        if (isalpha(text[i])) {
            tokens[*token_count][j++] = tolower(text[i]);
        } else if (j > 0) {
            tokens[*token_count][j] = '\0';
            (*token_count)++;
            j = 0;
        }
        i++;
    }
    if (j > 0) {
        tokens[*token_count][j] = '\0';
        (*token_count)++;
    }
}

void vectorize(char tokens[MAX_TOKENS][MAX_WORD_LENGTH], int token_count, char *dictionary_keys[], int dictionary_values[], int vector[MAX_TOKENS]) {
    for (int i = 0; i < token_count; i++) {
        for (int j = 0; dictionary_keys[j] != NULL; j++) {
            if (strcmp(tokens[i], dictionary_keys[j]) == 0) {
                vector[dictionary_values[j]]++;
                break;
            }
        }
    }
}

int main() {
    char text[] = "Natural language processing is fascinating";
    char *dictionary_keys[] = {"natural", "language", "processing", "is", "fascinating", NULL};
    int dictionary_values[] = {0, 1, 2, 3, 4};
    int vector[MAX_TOKENS] = {0};
    char tokens[MAX_TOKENS][MAX_WORD_LENGTH];
    int token_count = 0;

    tokenize(text, tokens, &token_count);
    vectorize(tokens, token_count, dictionary_keys, dictionary_values, vector);

    for (int i = 0; i < MAX_TOKENS; i++) {
        if (dictionary_keys[i] != NULL) {
            printf("%d ", vector[dictionary_values[i]]);
        } else {
            break;
        }
    }
    printf("\n");

    return 0;
}