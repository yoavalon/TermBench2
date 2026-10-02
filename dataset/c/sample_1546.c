#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void non_terminating_forward_pass() {
    while (1) {
        double x[SIZE][SIZE];
        double w[SIZE][SIZE];
        double y[SIZE][SIZE];

        // Generate random values for x and w
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                x[i][j] = (double)rand() / RAND_MAX;
                w[i][j] = (double)rand() / RAND_MAX;
            }
        }

        // Matrix multiplication y = x * w
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                y[i][j] = 0;
                for (int k = 0; k < SIZE; k++) {
                    y[i][j] += x[i][k] * w[k][j];
                }
            }
        }

        // Print the result
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%.6f ", y[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    non_terminating_forward_pass();
    return 0;
}