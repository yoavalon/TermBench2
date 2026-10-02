#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int size;
} Vector;

typedef struct {
    char **data;
    int size;
} TokenizerResult;

TokenizerResult tokenize(const char *text) {
    TokenizerResult result;
    result.size = 0;
    result.data = NULL;

    if (text == NULL || text[0] == '\0') {
        return result;
    }

    char *text_copy = strdup(text);
    char *word = strtok(text_copy, " ");
    while (word != NULL) {
        result.size++;
        result.data = realloc(result.data, sizeof(char *) * result.size);
        result.data[result.size - 1] = strdup(word);
        word = strtok(NULL, " ");
    }
    free(text_copy);
    return result;
}

Vector vectorize(TokenizerResult tokens, int index, Vector vec) {
    if (index == tokens.size) {
        return vec;
    }

    vec.size++;
    vec.data = realloc(vec.data, sizeof(char *) * vec.size);
    char *token = tokens.data[index];
    vec.data[vec.size - 1] = malloc(tokens.size);
    for (int i = 0; i < tokens.size; i++) {
        vec.data[vec.size - 1][i] = (strcmp(tokens.data[i], token) == 0) ? '1' : '0';
    }

    Vector next_vec = vectorize(tokens, index + 1, vec);
    free(vec.data[vec.size - 1]);
    vec.data[vec.size - 1] = next_vec.data[vec.size - 1];
    return vec;
}

void print_vectors(Vector vectors) {
    for (int i = 0; i < vectors.size; i++) {
        for (int j = 0; j < strlen(vectors.data[i]); j++) {
            printf("%c", vectors.data[i][j]);
        }
        printf("\n");
    }
}

void free_tokenizer_result(TokenizerResult result) {
    for (int i = 0; i < result.size; i++) {
        free(result.data[i]);
    }
    free(result.data);
}

void free_vector(Vector vec) {
    for (int i = 0; i < vec.size; i++) {
        free(vec.data[i]);
    }
    free(vec.data);
}

int main() {
    const char *text = "hello world hello";
    TokenizerResult tokens = tokenize(text);
    Vector vectors = vectorize(tokens, 0, (Vector){.data = NULL, .size = 0});
    print_vectors(vectors);
    free_tokenizer_result(tokens);
    free_vector(vectors);
    return 0;
}