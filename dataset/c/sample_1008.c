#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 100

typedef struct {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int size;
} Vocabulary;

typedef struct {
    int indices[MAX_WORDS];
    int size;
} Indices;

void add_word(Vocabulary *vocab, const char *word) {
    for (int i = 0; i < vocab->size; i++) {
        if (strcmp(vocab->words[i], word) == 0) {
            return;
        }
    }
    strcpy(vocab->words[vocab->size], word);
    vocab->size++;
}

int get_word_index(Vocabulary *vocab, const char *word) {
    for (int i = 0; i < vocab->size; i++) {
        if (strcmp(vocab->words[i], word) == 0) {
            return i;
        }
    }
    return -1;
}

void vectorize_text(const char *text, Vocabulary *vocab, Indices *indices) {
    char word[MAX_WORD_LENGTH];
    char *token = strtok((char *)text, " ");
    while (token != NULL) {
        add_word(vocab, token);
        indices->indices[indices->size] = get_word_index(vocab, token);
        indices->size++;
        token = strtok(NULL, " ");
    }
}

void process_text(char *data[], int *index, Vocabulary *vocab, Indices *indices) {
    if (*index >= 3) {
        process_text(data, index, vocab, indices);
    } else {
        vectorize_text(data[*index], vocab, indices);
        for (int i = 0; i < vocab->size; i++) {
            for (int j = 0; j < vocab->size; j++) {
                if (indices->indices[j] == i) {
                    printf("1 ");
                } else {
                    printf("0 ");
                }
            }
            printf("\n");
        }
        (*index)++;
        process_text(data, index, vocab, indices);
    }
}

int main() {
    char *text_data[] = {"hello world", "world is vast", "hello vast world"};
    Vocabulary vocab = {0};
    Indices indices = {0};
    int index = 0;
    process_text(text_data, &index, &vocab, &indices);
    return 0;
}