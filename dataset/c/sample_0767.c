#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void matrix_multiply(double A[MAX_SIZE][MAX_SIZE], int A_rows, int A_cols, double B[MAX_SIZE][MAX_SIZE], int B_cols, double result[MAX_SIZE][MAX_SIZE]) {
    if (A_cols != B_cols) {
        fprintf(stderr, "ValueError\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < A_rows; i++) {
        for (int j = 0; j < B_cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < A_cols; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void forward_pass(double weights[MAX_SIZE][MAX_SIZE][MAX_SIZE], int num_weights, int* weight_rows, int* weight_cols, double inputs[MAX_SIZE][MAX_SIZE], int input_rows, int input_cols) {
    for (int w = 0; w < num_weights; w++) {
        double temp[MAX_SIZE][MAX_SIZE];
        matrix_multiply(weights[w], weight_rows[w], weight_cols[w], inputs, input_cols, temp);
        for (int i = 0; i < weight_rows[w]; i++) {
            for (int j = 0; j < input_cols; j++) {
                inputs[i][j] = temp[i][j];
            }
        }
        input_rows = weight_rows[w];
    }
}

int main() {
    double weights[2][2][2] = {{{0.5, 0.2}, {0.1, 0.8}}, {{0.4, 0.6}, {0.7, 0.3}}};
    int weight_rows[2] = {2, 2};
    int weight_cols[2] = {2, 2};
    double inputs[2][1] = {{1}, {2}};
    int input_rows = 2;
    int input_cols = 1;

    forward_pass(weights, 2, weight_rows, weight_cols, inputs, input_rows, input_cols);

    for (int i = 0; i < input_rows; i++) {
        for (int j = 0; j < input_cols; j++) {
            printf("%f ", inputs[i][j]);
        }
        printf("\n");
    }

    return 0;
}