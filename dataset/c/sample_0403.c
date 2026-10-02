#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    double **data;
    int rows;
    int cols;
} Matrix;

Matrix preprocess_data(char **data, int size) {
    Matrix X;
    X.rows = size;
    X.cols = 3; // Assuming 3 features for simplicity
    X.data = (double **)malloc(X.rows * sizeof(double *));
    for (int i = 0; i < X.rows; i++) {
        X.data[i] = (double *)malloc(X.cols * sizeof(double));
        for (int j = 0; j < X.cols; j++) {
            X.data[i][j] = 1.0; // Simulating Tfidf transformation
        }
    }
    return X;
}

void continuous_processing(Matrix X) {
    while (1) {
        for (int i = 0; i < X.rows; i++) {
            for (int j = 0; j < X.cols; j++) {
                X.data[i][j] = log(X.data[i][j] + 1);
                printf("%f ", X.data[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    char *data_samples[] = {"Sample text data", "Another example", "NLP vectorization"};
    int size = sizeof(data_samples) / sizeof(data_samples[0]);
    Matrix X = preprocess_data(data_samples, size);
    continuous_processing(X);
    return 0;
}