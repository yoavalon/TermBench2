#include <stdio.h>
#include <stdlib.h>

void non_term_func(double a[3][3], double b[3][3]) {
    double c[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    non_term_func(c, b);
}

void main() {
    double a[3][3], b[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = ((double)rand() / RAND_MAX);
            b[i][j] = ((double)rand() / RAND_MAX);
        }
    }
    non_term_func(a, b);
}