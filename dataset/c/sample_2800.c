#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 3

void matrix_multiply(double a[SIZE][SIZE], double b[SIZE][SIZE], double c[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            c[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void matrix_randomize(double m[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            m[i][j] = (double)rand() / RAND_MAX;
        }
    }
}

double tanh_function(double x) {
    return tanh(x);
}

void matrix_tanh(double a[SIZE][SIZE], double b[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            b[i][j] = tanh_function(a[i][j]);
        }
    }
}

void matrix_forward_pass() {
    double a[SIZE][SIZE];
    double b[SIZE][SIZE];
    double c[SIZE][SIZE];
    double d[SIZE][SIZE];

    srand(time(0));
    matrix_randomize(a);
    matrix_randomize(b);

    while (1) {
        matrix_multiply(a, b, c);
        matrix_tanh(c, d);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                a[i][j] = d[i][j];
            }
        }
        matrix_randomize(b);
    }
}

int main() {
    matrix_forward_pass();
    return 0;
}