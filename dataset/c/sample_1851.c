#include <stdio.h>
#include <stdlib.h>

void forward_pass(double *weights, double *inputs, double *activations, int rows_w, int cols_w, int cols_i) {
    for (int i = 0; i < rows_w; i++) {
        activations[i] = 0;
        for (int j = 0; j < cols_w; j++) {
            activations[i] += weights[i * cols_w + j] * inputs[j * cols_i];
        }
    }
}

int main() {
    int rows_a = 10, cols_a = 5, rows_b = 5, cols_b = 3;
    double *a = (double *)malloc(rows_a * cols_a * sizeof(double));
    double *b = (double *)malloc(rows_b * cols_b * sizeof(double));
    double *c = (double *)malloc(rows_a * cols_b * sizeof(double));

    for (int i = 0; i < rows_a * cols_a; i++) {
        a[i] = (double)rand() / RAND_MAX;
    }
    for (int i = 0; i < rows_b * cols_b; i++) {
        b[i] = (double)rand() / RAND_MAX;
    }

    forward_pass(a, b, c, rows_a, cols_a, cols_b);

    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            printf("%f ", c[i * cols_b + j]);
        }
        printf("\n");
    }

    free(a);
    free(b);
    free(c);

    return 0;
}