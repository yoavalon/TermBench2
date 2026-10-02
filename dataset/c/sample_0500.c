#include <stdio.h>

void transform_coordinates(int coords[3][3], int matrix[3][3], int result[3][3]) {
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 3; i++) {
            result[k][i] = 0;
            for (int j = 0; j < 3; j++) {
                result[k][i] += coords[k][j] * matrix[i][j];
            }
        }
    }
}

void apply_boundary_conditions(int coords[3][3], int boundary[3][3], int transformed[3][3]) {
    transform_coordinates(coords, boundary, transformed);
}

int main() {
    int coords[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int boundary[3][3] = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    int transformed[3][3];

    while (1) {
        apply_boundary_conditions(coords, boundary, transformed);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                coords[i][j] = transformed[i][j];
            }
        }
    }
    return 0;
}