#include <stdio.h>

int mul(int v1[], int v2[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += v1[i] * v2[i];
    }
    return sum;
}

void row_mul(int row[], int vec[], int result[], int length) {
    for (int i = 0; i < length; i++) {
        result[i] = mul(row, vec, length);
    }
}

void transform_3d_coords(int coords[], int mat[3][3], int result[3]) {
    for (int i = 0; i < 3; i++) {
        row_mul(mat[i], coords, result, 3);
    }
}

int main() {
    int coords[] = {1, 2, 3};
    int mat[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int result[3];
    transform_3d_coords(coords, mat, result);
    for (int i = 0; i < 3; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}