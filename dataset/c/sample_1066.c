#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 5
#define LAYERS 3

void forward_pass(double matrix[ROWS][COLS], double weights[COLS][COLS], double bias[COLS], double result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0.0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += matrix[i][k] * weights[k][j];
            }
            result[i][j] += bias[j];
        }
    }
}

void recursive_forward(double matrix[ROWS][COLS], double weights_list[LAYERS][COLS][COLS], double bias_list[LAYERS][COLS], int index, double result[ROWS][COLS]) {
    double temp[ROWS][COLS];
    forward_pass(matrix, weights_list[index], bias_list[index], temp);
    if (index < LAYERS - 1) {
        recursive_forward(temp, weights_list, bias_list, index + 1, result);
    } else {
        recursive_forward(temp, weights_list, bias_list, 0, result);
    }
}

void main() {
    srand(time(NULL));
    double data[ROWS][COLS];
    double weights_list[LAYERS][COLS][COLS];
    double bias_list[LAYERS][COLS];
    double result[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            data[i][j] = ((double)rand() / RAND_MAX);
        }
    }

    for (int l = 0; l < LAYERS; l++) {
        for (int i = 0; i < COLS; i++) {
            for (int j = 0; j < COLS; j++) {
                weights_list[l][i][j] = ((double)rand() / RAND_MAX);
            }
        }
        for (int i = 0; i < COLS; i++) {
            bias_list[l][i] = ((double)rand() / RAND_MAX);
        }
    }

    while (1) {
        recursive_forward(data, weights_list, bias_list, 0, result);
    }
}