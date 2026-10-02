#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrix_operations() {
    while (1) {
        double a[3][3], b[3][3], c[3][3], d[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a[i][j] = (double)rand() / RAND_MAX;
                b[i][j] = (double)rand() / RAND_MAX;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                c[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                d[i][j] = c[i][j] + c[j][i];
            }
        }
    }
}

int main() {
    srand(time(NULL));
    matrix_operations();
    return 0;
}