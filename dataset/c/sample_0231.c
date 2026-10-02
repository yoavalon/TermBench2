#include <stdio.h>

#define ROWS 2
#define COLS 2

void multiply(int matrix_a[ROWS][COLS], int matrix_b[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
}

void transpose(int matrix[ROWS][COLS], int result[COLS][ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int forward_pass(int weights[ROWS][COLS], int input_data[COLS]) {
    int result = 0;
    for (int i = 0; i < ROWS; i++) {
        result += weights[i][0] * input_data[0] + weights[i][1] * input_data[1];
    }
    return result;
}

int activate(int data) {
    return data > 0 ? data : 0;
}

int main() {
    int matrix_a[ROWS][COLS] = {{1, 2}, {3, 4}};
    int matrix_b[ROWS][COLS] = {{2, 0}, {1, 2}};
    int product[ROWS][COLS];
    multiply(matrix_a, matrix_b, product);

    int transposed_a[COLS][ROWS];
    transpose(matrix_a, transposed_a);

    int weights[ROWS][COLS] = {{0, 0}, {0, 0}};
    weights[0][0] = 0.5;
    weights[0][1] = 0.2;
    weights[1][0] = 0.3;
    weights[1][1] = 0.4;
    int input_data[COLS] = {1, 0.5};

    int forward_output = forward_pass(weights, input_data);
    int activated_output = activate(forward_output);

    printf("Matrix Product:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    printf("Transposed A:\n");
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            printf("%d ", transposed_a[i][j]);
        }
        printf("\n");
    }

    printf("Neural Network Forward Pass Output:\n");
    printf("%d\n", forward_output);

    printf("Activated Output:\n");
    printf("%d\n", activated_output);

    return 0;
}