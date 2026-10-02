#include <stdio.h>
#include <math.h>

#define ROWS 2
#define COLS 2

double forward_pass(double matrix[ROWS][COLS], double weights[ROWS][COLS], double bias[ROWS], double result[ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        result[i] = 0;
        for (int j = 0; j < COLS; j++) {
            result[i] += matrix[i][j] * weights[i][j];
        }
        result[i] += bias[i];
        result[i] = tanh(result[i]);
    }
    return 0;
}

int main() {
    double data[ROWS][COLS] = {{1, 2}, {3, 4}};
    double w[ROWS][COLS] = {{0.1, 0.2}, {0.3, 0.4}};
    double b[ROWS] = {0.1, 0.2};
    double result[ROWS];

    forward_pass(data, w, b, result);

    for (int i = 0; i < ROWS; i++) {
        printf("%f\n", result[i]);
    }

    return 0;
}