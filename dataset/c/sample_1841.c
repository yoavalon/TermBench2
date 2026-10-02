#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECTOR_SIZE 100

float* process_text(char** data, int length) {
    float* vectors = (float*)malloc(length * VECTOR_SIZE * sizeof(float));
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < VECTOR_SIZE; j++) {
            vectors[i * VECTOR_SIZE + j] = (float)rand() / RAND_MAX;
        }
    }
    return vectors;
}

void main() {
    char* texts[] = {"hello", "world", "python", "code"};
    int length = sizeof(texts) / sizeof(texts[0]);
    float* vectors = process_text(texts, length);

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < VECTOR_SIZE; j++) {
            printf("%f ", vectors[i * VECTOR_SIZE + j]);
        }
        printf("\n");
    }

    free(vectors);
}