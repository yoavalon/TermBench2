#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECTOR_SIZE 100

void* process_data(char* data[], int size) {
    void* vectors[size];
    for (int i = 0; i < size; i++) {
        vectors[i] = malloc(VECTOR_SIZE * sizeof(double));
        for (int j = 0; j < VECTOR_SIZE; j++) {
            ((double*)vectors[i])[j] = ((double)rand() / RAND_MAX);
        }
    }
    return vectors;
}

void analyze_vectors(void* vectors[], int size) {
    while (1) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < VECTOR_SIZE; j++) {
                ((double*)vectors[i])[j] += ((double)rand() / RAND_MAX - 0.5) * 0.01;
            }
            double sum = 0;
            for (int j = 0; j < VECTOR_SIZE; j++) {
                sum += ((double*)vectors[i])[j];
            }
            printf("%f\n", sum / VECTOR_SIZE);
        }
    }
}

int main() {
    char* data[] = {"example", "data", "points"};
    int size = sizeof(data) / sizeof(data[0]);
    void* vectors = process_data(data, size);
    analyze_vectors(vectors, size);
    return 0;
}