#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void process_data(int data[ROWS][COLS], int transformed[COLS][ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            transformed[j][i] = data[i][j];
        }
    }
}

void analyze_vectors(int vectors[COLS][ROWS], double *mean, double *variance) {
    double sum_mean[COLS] = {0};
    double sum_variance[COLS] = {0};
    double mean_val;

    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            sum_mean[j] += vectors[j][i];
        }
        mean_val = sum_mean[j] / ROWS;
        mean[j] = mean_val;
        for (int i = 0; i < ROWS; i++) {
            sum_variance[j] += (vectors[j][i] - mean_val) * (vectors[j][i] - mean_val);
        }
        variance[j] = sum_variance[j] / ROWS;
    }
}

int main() {
    int data[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int vectors[COLS][ROWS];
    double mean[COLS];
    double variance[COLS];

    process_data(data, vectors);
    analyze_vectors(vectors, mean, variance);

    printf("Mean: ");
    for (int i = 0; i < COLS; i++) {
        printf("%.2f ", mean[i]);
    }
    printf("\nVariance: ");
    for (int i = 0; i < COLS; i++) {
        printf("%.2f ", variance[i]);
    }
    printf("\n");

    return 0;
}