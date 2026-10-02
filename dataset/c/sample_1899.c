#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void process_text(char** data, int size, double** result) {
    double** vectors = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        vectors[i] = (double*)malloc(strlen(data[i]) * sizeof(double));
        for (int j = 0; j < strlen(data[i]); j++) {
            vectors[i][j] = (double)data[i][j];
        }
    }

    double* norms = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        norms[i] = 0;
        for (int j = 0; j < strlen(data[i]); j++) {
            norms[i] += vectors[i][j] * vectors[i][j];
        }
        norms[i] = sqrt(norms[i]);
    }

    *result = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        (*result)[i] = (double*)malloc(strlen(data[i]) * sizeof(double));
        for (int j = 0; j < strlen(data[i]); j++) {
            (*result)[i][j] = vectors[i][j] / norms[i];
        }
    }

    for (int i = 0; i < size; i++) {
        free(vectors[i]);
    }
    free(vectors);
    free(norms);
}

int main() {
    char* data[] = {"hello", "world"};
    int size = sizeof(data) / sizeof(data[0]);
    double** result;

    process_text(data, size, &result);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < strlen(data[i]); j++) {
            printf("%.2f ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}