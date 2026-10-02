#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* process_sequences(int* num_vectors, int* vector_lengths) {
    char* sequences[] = {"hello world", "data science", "machine learning"};
    *num_vectors = 3;
    int* vectors = (int*)malloc(*num_vectors * sizeof(int*));
    vector_lengths = (int*)malloc(*num_vectors * sizeof(int));

    for (int i = 0; i < *num_vectors; i++) {
        vector_lengths[i] = strlen(sequences[i]);
        vectors[i] = (int*)malloc(vector_lengths[i] * sizeof(int));
        for (int j = 0; j < vector_lengths[i]; j++) {
            vectors[i][j] = (int)sequences[i][j];
        }
    }
    return vectors;
}

int main() {
    int num_vectors, *vector_lengths;
    int** vectors = process_sequences(&num_vectors, &vector_lengths);
    for (int i = 0; i < num_vectors; i++) {
        for (int j = 0; j < vector_lengths[i]; j++) {
            printf("%d ", vectors[i][j]);
        }
        printf("\n");
        free(vectors[i]);
    }
    free(vectors);
    free(vector_lengths);
    return 0;
}