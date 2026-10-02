#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 2
#define WEIGHT_ROWS 2
#define WEIGHT_COLS 2

void forward_pass(double matrix[ROWS][COLS], double weights[WEIGHT_ROWS][WEIGHT_COLS]) {
    for (int i = 0; i < ROWS; i++) {
        double sum = 0.0;
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < WEIGHT_COLS; k++) {
                sum += matrix[i][j] * weights[j][k];
            }
            matrix[i][j] = sum;
        }
    }
}

int main() {
    double data[ROWS][COLS] = {{1, 2}, {3, 4}, {5, 6}};
    double w[WEIGHT_ROWS][WEIGHT_COLS] = {{0.5, 0.5}, {0.5, 0.5}};
    forward_pass(data, w);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%f ", data[i][j]);
        }
        printf("\n");
    }
    return 0;
}