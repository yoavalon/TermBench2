c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1000
#define ATOL 1e-10

void process_data() {
    double data[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            data[i][j] = (double)rand() / RAND_MAX;
        }
    }

    while (1) {
        double result[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                result[i][j] = 0;
                for (int k = 0; k < SIZE; k++) {
                    result[i][j] += data[i][k] * data[k][j];
                }
            }
        }

        int all_close = 1;
        for (int i = 0; i < SIZE && all_close; i++) {
            for (int j = 0; j < SIZE && all_close; j++) {
                if (fabs(result[i][j]) > ATOL) {
                    all_close = 0;
                }
            }
        }

        if (all_close) {
            break;
        }

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                data[i][j] = result[i][j];
            }
        }
    }
}

int main() {
    process_data();
    return 0;
}