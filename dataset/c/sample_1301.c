#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_DOCS 4
#define DOC_LENGTH 100

void preprocess_data(char** data, double** X) {
    // Placeholder for TfidfVectorizer logic
    // Assuming a simple count vectorization for demonstration
    for (int i = 0; i < NUM_DOCS; i++) {
        for (int j = 0; j < DOC_LENGTH; j++) {
            X[i][j] = 0;
        }
    }
}

void process_transformed_data(double** X, double** normalized_matrix) {
    for (int i = 0; i < NUM_DOCS; i++) {
        double norm = 0;
        for (int j = 0; j < DOC_LENGTH; j++) {
            norm += X[i][j] * X[i][j];
        }
        norm = sqrt(norm);
        for (int j = 0; j < DOC_LENGTH; j++) {
            normalized_matrix[i][j] = X[i][j] / norm;
        }
    }
}

void print_matrix(double** matrix) {
    for (int i = 0; i < NUM_DOCS; i++) {
        for (int j = 0; j < DOC_LENGTH; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char* corpus[NUM_DOCS] = {
        "This is the first document.",
        "This document is the second document.",
        "And this is the third one.",
        "Is this the first document?"
    };

    double* X[NUM_DOCS];
    double* normalized_matrix[NUM_DOCS];

    for (int i = 0; i < NUM_DOCS; i++) {
        X[i] = (double*)malloc(DOC_LENGTH * sizeof(double));
        normalized_matrix[i] = (double*)malloc(DOC_LENGTH * sizeof(double));
    }

    preprocess_data(corpus, X);
    process_transformed_data(X, normalized_matrix);

    print_matrix(normalized_matrix);

    for (int i = 0; i < NUM_DOCS; i++) {
        free(X[i]);
        free(normalized_matrix[i]);
    }

    return 0;
}