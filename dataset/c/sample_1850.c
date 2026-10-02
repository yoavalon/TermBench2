#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VOCAB_SIZE 3
#define WORD_LENGTH 20

typedef struct {
    char *word;
    int index;
} Vocabulary;

Vocabulary vocab[] = {
    {"hello", 0},
    {"world", 1},
    {"test", 2}
};

int* vectorize_text(const char *text, int vocab_size) {
    int *vec = (int *)calloc(vocab_size, sizeof(int));
    char *text_copy = strdup(text);
    char *token = strtok(text_copy, " ");
    while (token != NULL) {
        for (int i = 0; i < vocab_size; i++) {
            if (strcmp(token, vocab[i].word) == 0) {
                vec[vocab[i].index] += 1;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    free(text_copy);
    return vec;
}

int main() {
    const char *text = "hello world test";
    int vocab_size = VOCAB_SIZE;
    int *result = vectorize_text(text, vocab_size);
    for (int i = 0; i < vocab_size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}