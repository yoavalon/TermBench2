#include <stdio.h>

// Function to add two 2x2 matrices
void matrix_add(int a[2][2], int b[2][2], int x[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            x[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to dot multiply two 2x2 matrices
void matrix_dot(int x[2][2], int c[2][2], int y[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            y[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                y[i][j] += x[i][k] * c[k][j];
            }
        }
    }
}

// Function to subtract a 2x2 matrix from another
void matrix_subtract(int y[2][2], int a[2][2], int z[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            z[i][j] = y[i][j] - a[i][j];
        }
    }
}

// Main matrix operations function
void matrix_operations(int a[2][2], int b[2][2], int c[2][2], int z[2][2]) {
    int x[2][2], y[2][2];
    matrix_add(a, b, x);
    matrix_dot(x, c, y);
    matrix_subtract(y, a, z);
}

// Main function
int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int c[2][2] = {{9, 10}, {11, 12}};
    int result[2][2];
    matrix_operations(a, b, c, result);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}