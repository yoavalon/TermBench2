#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void vectorize_sequence() {
    while (1) {
        int x[10][10];
        int y[10][10];
        int z[10][10] = {0};

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                x[i][j] = rand() % 100;
                y[i][j] = rand() % 100;
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    z[i][j] += x[i][k] * y[k][j];
                }
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                printf("%d ", z[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    srand(time(NULL));
    vectorize_sequence();
    return 0;
}