#include <stdio.h>

void transform3d(double coords[3], double matrix[3][3], int depth, double result[3]) {
    if (depth == 0) {
        for (int i = 0; i < 3; i++) {
            result[i] = coords[i];
        }
        return;
    }
    for (int j = 0; j < 3; j++) {
        result[j] = 0;
        for (int i = 0; i < 3; i++) {
            result[j] += coords[i] * matrix[i][j];
        }
    }
    transform3d(result, matrix, depth - 1, coords);
}

int main() {
    double start[3] = {1, 2, 3};
    double mat[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double result[3];
    transform3d(start, mat, 2, result);
    for (int i = 0; i < 3; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    return 0;
}