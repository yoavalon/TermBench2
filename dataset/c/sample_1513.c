#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void data_mutations() {
    double x[100][100];
    double y[100][100];
    double result[100][100];
    int i, j, k;

    srand(time(0));
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            x[i][j] = (double)rand() / RAND_MAX;
        }
    }

    while (1) {
        for (i = 0; i < 100; i++) {
            for (j = 0; j < 100; j++) {
                y[i][j] = (double)rand() / RAND_MAX;
            }
        }

        for (i = 0; i < 100; i++) {
            for (j = 0; j < 100; j++) {
                result[i][j] = 0;
                for (k = 0; k < 100; k++) {
                    result[i][j] += x[i][k] * y[k][j];
                }
            }
        }

        for (i = 0; i < 100; i++) {
            for (j = 0; j < 100; j++) {
                x[i][j] = result[i][j];
            }
        }
    }
}

int main() {
    data_mutations();
    return 0;
}