#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define VECTOR_SIZE 100
#define MAX_WORDS 100

void vectorize_text(const char* data[], int num_texts, double vectors[][VECTOR_SIZE]) {
    for (int i = 0; i < num_texts; i++) {
        const char* text = data[i];
        const char* word = strtok((char*)text, " ");
        while (word != NULL) {
            unsigned long hash = 5381;
            for (const char* c = word; *c != '\0'; c++) {
                hash = ((hash << 5) + hash) + *c;
            }
            vectors[i][hash % VECTOR_SIZE] += 1;
            word = strtok(NULL, " ");
        }
    }
}

void normalize_vectors(double vectors[][VECTOR_SIZE], int num_texts) {
    for (int i = 0; i < num_texts; i++) {
        double norm = 0.0;
        for (int j = 0; j < VECTOR_SIZE; j++) {
            norm += vectors[i][j] * vectors[i][j];
        }
        norm = sqrt(norm);
        for (int j = 0; j < VECTOR_SIZE; j++) {
            vectors[i][j] /= norm;
        }
    }
}

int main() {
    const char* dataset[] = {"hello world", "hello universe", "goodbye world"};
    int num_texts = sizeof(dataset) / sizeof(dataset[0]);
    double vectors[num_texts][VECTOR_SIZE];

    vectorize_text(dataset, num_texts, vectors);
    normalize_vectors(vectors, num_texts);

    while (1) {
        // Non-terminating loop
    }

    return 0;
}