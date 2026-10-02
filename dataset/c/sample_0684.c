#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vectorize_text(const char *text, char ***vectors, int *vectors_size, int depth) {
    if (depth == 0) {
        return;
    }
    char *token = strtok((char *)text, " ");
    while (token != NULL) {
        *vectors = realloc(*vectors, (*vectors_size + 1) * sizeof(char *));
        (*vectors)[*vectors_size] = malloc(strlen(token) + 1);
        strcpy((*vectors)[*vectors_size], token);
        (*vectors_size)++;
        token = strtok(NULL, " ");
    }
    vectorize_text(text, vectors, vectors_size, depth - 1);
}

int main() {
    const char *text = "recursion in natural language processing";
    char **vectors = NULL;
    int vectors_size = 0;
    vectorize_text(text, &vectors, &vectors_size, 3);
    for (int i = 0; i < vectors_size; i++) {
        printf("%s\n", vectors[i]);
        free(vectors[i]);
    }
    free(vectors);
    return 0;
}