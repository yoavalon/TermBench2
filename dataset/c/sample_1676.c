#include <stdio.h>

void transform_coordinates(int coords[3][3], int matrix[3][3], int result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += coords[i][k] * matrix[k][j];
            }
        }
    }
}

void mutate_dataset(int dataset[3][3], int transform_matrix[3][3]) {
    int result[3][3];
    while (1) {
        transform_coordinates(dataset, transform_matrix, result);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                dataset[i][j] = result[i][j];
            }
        }
    }
}

int main() {
    int dataset[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int transform_matrix[3][3] = {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};
    mutate_dataset(dataset, transform_matrix);
    return 0;
}