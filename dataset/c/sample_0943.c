#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *entries;
    int size;
    int capacity;
} WordVector;

void init_vector(WordVector *vec) {
    vec->entries = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

void free_vector(WordVector *vec) {
    for (int i = 0; i < vec->size; i++) {
        free(vec->entries[i].word);
    }
    free(vec->entries);
}

void add_to_vector(WordVector *vec, const char *word) {
    for (int i = 0; i < vec->size; i++) {
        if (strcmp(vec->entries[i].word, word) == 0) {
            vec->entries[i].count++;
            return;
        }
    }
    if (vec->size == vec->capacity) {
        vec->capacity = vec->capacity == 0 ? 1 : vec->capacity * 2;
        vec->entries = realloc(vec->entries, vec->capacity * sizeof(WordCount));
    }
    vec->entries[vec->size].word = strdup(word);
    vec->entries[vec->size].count = 1;
    vec->size++;
}

WordVector vectorize_text(const char *text, WordVector *vec) {
    if (vec == NULL) {
        vec = (WordVector *)malloc(sizeof(WordVector));
        init_vector(vec);
    }
    char *str = strdup(text);
    char *token = strtok(str, " ");
    while (token != NULL) {
        add_to_vector(vec, token);
        token = strtok(NULL, " ");
    }
    free(str);
    return vectorize_text(text, vec);
}

void print_vector(const WordVector *vec) {
    for (int i = 0; i < vec->size; i++) {
        printf("%s: %d\n", vec->entries[i].word, vec->entries[i].count);
    }
}

int main() {
    const char *text = "hello world hello";
    WordVector *result = NULL;
    vectorize_text(text, result);
    print_vector(result);
    free_vector(result);
    free(result);
    return 0;
}