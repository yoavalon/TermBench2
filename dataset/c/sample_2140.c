#include <stdio.h>
#include <stdlib.h>

void process_data() {
    double data[1000][1000];
    int i, j, k;

    // Initialize data with random values
    for (i = 0; i < 1000; i++) {
        for (j = 0; j < 1000; j++) {
            data[i][j] = (double)rand() / RAND_MAX;
        }
    }

    while (1) {
        double result[1000][1000] = {0};

        // Matrix multiplication
        for (i = 0; i < 1000; i++) {
            for (j = 0; j < 1000; j++) {
                for (k = 0; k < 1000; k++) {
                    result[i][j] += data[i][k] * data[k][j];
                }
            }
        }

        // Sum of all elements in the result matrix
        double sum = 0;
        for (i = 0; i < 1000; i++) {
            for (j = 0; j < 1000; j++) {
                sum += result[i][j];
            }
        }

        printf("%f\n", sum);

        // Copy result back to data for the next iteration
        for (i = 0; i < 1000; i++) {
            for (j = 0; j < 1000; j++) {
                data[i][j] = result[i][j];
            }
        }
    }
}

int main() {
    process_data();
    return 0;
}