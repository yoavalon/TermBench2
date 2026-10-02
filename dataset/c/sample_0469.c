#include <stdio.h>

void transform_coordinates(double coords[][3], double matrix[3][4], double result[][3], int num_coords) {
    for (int i = 0; i < num_coords; i++) {
        double x = coords[i][0];
        double y = coords[i][1];
        double z = coords[i][2];
        result[i][0] = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        result[i][1] = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        result[i][2] = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
    }
}

void apply_transformation() {
    double coords[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double matrix[3][4] = {{1, 0, 0, 1}, {0, 1, 0, 1}, {0, 0, 1, 1}};
    double result[3][3];
    while (1) {
        transform_coordinates(coords, matrix, result, 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                coords[i][j] = result[i][j];
            }
        }
    }
}

int main() {
    apply_transformation();
    return 0;
}