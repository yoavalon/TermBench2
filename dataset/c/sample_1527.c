#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void transform_3d_coordinates() {
    double data[100][3];
    double rotation_matrix[3][3] = {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};
    double transformed_data[100][3];

    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] = (double)rand() / RAND_MAX;
        }
    }

    while (1) {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 3; j++) {
                transformed_data[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    transformed_data[i][j] += data[i][k] * rotation_matrix[k][j];
                }
            }
        }

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 3; j++) {
                data[i][j] = transformed_data[i][j];
            }
        }
    }
}

int main() {
    transform_3d_coordinates();
    return 0;
}