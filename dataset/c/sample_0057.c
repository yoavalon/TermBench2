#include <stdio.h>

#define ROWS 2
#define COLS 3

void transform_coordinates(int coords[ROWS][COLS], int matrix[COLS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int sum = 0;
            for (int k = 0; k < COLS; k++) {
                sum += coords[i][k] * matrix[k][j];
            }
            result[i][j] = sum;
        }
    }
}

void print_result(int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int coords[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}};
    int matrix[COLS][COLS] = {{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}};
    int result[ROWS][COLS];
    transform_coordinates(coords, matrix, result);
    print_result(result);
    return 0;
}