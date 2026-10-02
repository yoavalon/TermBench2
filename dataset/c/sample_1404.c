#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_TOKENS 100
#define MAX_WORD_LENGTH 100

typedef struct {
    char data[MAX_ITEMS][MAX_WORD_LENGTH];
    int count;
} Vectorizer;

void Vectorizer_init(Vectorizer *self, const char *data[], int data_count) {
    for (int i = 0; i < data_count; i++) {
        strncpy(self->data[i], data[i], MAX_WORD_LENGTH);
    }
    self->count = data_count;
}

void tokenize(Vectorizer *self, char tokens[MAX_ITEMS][MAX_TOKENS][MAX_WORD_LENGTH], int *token_counts) {
    for (int i = 0; i < self->count; i++) {
        char *str = self->data[i];
        char *token = strtok(str, " ");
        int j = 0;
        while (token != NULL) {
            strncpy(tokens[i][j], token, MAX_WORD_LENGTH);
            token = strtok(NULL, " ");
            j++;
        }
        token_counts[i] = j;
    }
}

void create_vocab(char tokens[MAX_ITEMS][MAX_TOKENS][MAX_WORD_LENGTH], int token_counts[], bool vocab[MAX_ITEMS][MAX_ITEMS]) {
    int vocab_size = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        for (int j = 0; j < MAX_ITEMS; j++) {
            vocab[i][j] = false;
        }
    }
    for (int i = 0; i < self->count; i++) {
        for (int j = 0; j < token_counts[i]; j++) {
            bool found = false;
            for (int k = 0; k < vocab_size; k++) {
                if (strcmp(tokens[i][j], tokens[k][0]) == 0) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                strncpy(tokens[vocab_size][0], tokens[i][j], MAX_WORD_LENGTH);
                vocab_size++;
            }
        }
    }
}

void vectorize(Vectorizer *self, char tokens[MAX_ITEMS][MAX_TOKENS][MAX_WORD_LENGTH], int token_counts[], bool vocab[MAX_ITEMS][MAX_ITEMS], int vectorized_data[MAX_ITEMS][MAX_ITEMS]) {
    int vocab_size = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        for (int j = 0; j < MAX_ITEMS; j++) {
            vectorized_data[i][j] = 0;
        }
    }
    for (int i = 0; i < self->count; i++) {
        for (int j = 0; j < token_counts[i]; j++) {
            for (int k = 0; k < vocab_size; k++) {
                if (strcmp(tokens[i][j], tokens[k][0]) == 0) {
                    vectorized_data[i][k]++;
                    break;
                }
            }
        }
    }
}

int main() {
    const char *data[] = {
        "the quick brown fox jumps over the lazy dog",
        "never jump over the lazy dog quickly",
        "foxes are quick and cunning animals"
    };
    int data_count = sizeof(data) / sizeof(data[0]);

    Vectorizer vectorizer;
    Vectorizer_init(&vectorizer, data, data_count);

    char tokens[MAX_ITEMS][MAX_TOKENS][MAX_WORD_LENGTH];
    int token_counts[MAX_ITEMS];
    tokenize(&vectorizer, tokens, token_counts);

    bool vocab[MAX_ITEMS][MAX_ITEMS];
    create_vocab(tokens, token_counts, vocab);

    int vectorized_data[MAX_ITEMS][MAX_ITEMS];
    vectorize(&vectorizer, tokens, token_counts, vocab, vectorized_data);

    for (int i = 0; i < data_count; i++) {
        for (int j = 0; j < vocab_size; j++) {
            printf("%d ", vectorized_data[i][j]);
        }
        printf("\n");
    }

    return 0;
}