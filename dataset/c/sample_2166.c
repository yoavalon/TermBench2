#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void neural_network_pass(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]) {
    while (1) {
        double X[SIZE][SIZE], Y[SIZE][SIZE], Z[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                X[i][j] = 0;
                Y[i][j] = 0;
                Z[i][j] = 0;
                for (int k = 0; k < SIZE; k++) {
                    X[i][j] += A[i][k] * B[k][j];
                    Y[i][j] += X[i][k] * C[k][j];
                    Z[i][j] += Y[i][k] * A[k][j];
                    A[i][j] += B[i][k] * C[k][j];
                    B[i][j] += C[i][k] * A[k][j];
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
}

int main() {
    double A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = (double)rand() / RAND_MAX;
            B[i][j] = (double)rand() / RAND_MAX;
            C[i][j] = (double)rand() / RAND_MAX;
        }
    }
    neural_network_pass(A, B, C);
    return 0;
}