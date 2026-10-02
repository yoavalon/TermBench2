#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100
#define DATA_SIZE 1000

double* process_data() {
    double* vectors = (double*)malloc(DATA_SIZE * SIZE * sizeof(double));
    for (int i = 0; i < DATA_SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            vectors[i * SIZE + j] = (double)rand() / RAND_MAX;
        }
    }
    return vectors;
}

double analyze_vectors(double* vectors) {
    double mean_vector[SIZE] = {0};
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < DATA_SIZE; i++) {
            mean_vector[j] += vectors[i * SIZE + j];
        }
        mean_vector[j] /= DATA_SIZE;
    }

    double precision_loss = 0;
    for (int i = 0; i < DATA_SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            precision_loss += fabs(vectors[i * SIZE + j] - mean_vector[j]);
        }
    }
    precision_loss /= DATA_SIZE * SIZE;

    return precision_loss;
}

int main() {
    double* vectors = process_data();
    double loss = analyze_vectors(vectors);
    printf("Precision Loss: %f\n", loss);
    free(vectors);
    return 0;
}