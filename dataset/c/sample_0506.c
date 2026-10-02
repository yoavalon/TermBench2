#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_ITEMS 3
#define MAX_TOKENS 100
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCounter;

void preprocess_text(char data[][MAX_WORD_LENGTH], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < strlen(data[i]); j++) {
            data[i][j] = tolower(data[i][j]);
        }
        for (int j = strlen(data[i]) - 1; j >= 0; j--) {
            if (!isalpha(data[i][j])) {
                data[i][j] = '\0';
            } else {
                break;
            }
        }
    }
}

void tokenize_text(char data[][MAX_WORD_LENGTH], int size, char tokens[][MAX_TOKENS][MAX_WORD_LENGTH]) {
    for (int i = 0; i < size; i++) {
        int token_count = 0;
        char *token = strtok(data[i], " ");
        while (token != NULL) {
            strcpy(tokens[i][token_count], token);
            token = strtok(NULL, " ");
            token_count++;
        }
    }
}

void create_vectors(char tokens[][MAX_TOKENS][MAX_WORD_LENGTH], int size, WordCounter vectors[][MAX_TOKENS]) {
    for (int i = 0; i < size; i++) {
        int word_count = 0;
        for (int j = 0; j < MAX_TOKENS; j++) {
            if (tokens[i][j][0] == '\0') {
                break;
            }
            int found = 0;
            for (int k = 0; k < word_count; k++) {
                if (strcmp(vectors[i][k].word, tokens[i][j]) == 0) {
                    vectors[i][k].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(vectors[i][word_count].word, tokens[i][j]);
                vectors[i][word_count].count = 1;
                word_count++;
            }
        }
    }
}

int main() {
    char sample_data[MAX_ITEMS][MAX_WORD_LENGTH] = {
        "This is a sample text for vectorization.",
        "Another example, to demonstrate the process.",
        "And one more for good measure."
    };
    char processed[MAX_ITEMS][MAX_WORD_LENGTH];
    char tokens[MAX_ITEMS][MAX_TOKENS][MAX_WORD_LENGTH];
    WordCounter vectors[MAX_ITEMS][MAX_TOKENS];

    preprocess_text(sample_data, MAX_ITEMS);
    tokenize_text(processed, MAX_ITEMS, tokens);
    create_vectors(tokens, MAX_ITEMS, vectors);

    while (1) {
        char new_data[MAX_ITEMS][MAX_WORD_LENGTH] = {
            "New text to vectorize, continuously.",
            "Testing the non-terminating nature of the program."
        };
        char processed_new[MAX_ITEMS][MAX_WORD_LENGTH];
        char tokens_new[MAX_ITEMS][MAX_TOKENS][MAX_WORD_LENGTH];
        WordCounter vectors_new[MAX_ITEMS][MAX_TOKENS];

        preprocess_text(new_data, MAX_ITEMS);
        tokenize_text(processed_new, MAX_ITEMS, tokens_new);
        create_vectors(tokens_new, MAX_ITEMS, vectors_new);

        for (int i = 0; i < MAX_ITEMS; i++) {
            for (int j = 0; j < MAX_TOKENS; j++) {
                if (vectors_new[i][j].word[0] == '\0') {
                    break;
                }
                vectors[i][j] = vectors_new[i][j];
            }
        }
    }

    return 0;
}