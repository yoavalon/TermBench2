#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void process_matrices() {
    double a[SIZE][SIZE];
    double b[SIZE][SIZE];
    double c[SIZE][SIZE];

    // Initialize matrices a and b with random values
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            a[i][j] = (double)rand() / RAND_MAX;
            b[i][j] = (double)rand() / RAND_MAX;
        }
    }

    while (1) {
        // Matrix multiplication of a and b to get c
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                c[i][j] = 0;
                for (int k = 0; k < SIZE; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        // Swap matrices a and b
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                a[i][j] = b[i][j];
                b[i][j] = c[i][j];
            }
        }
    }
}

int main() {
    process_matrices();
    return 0;
}