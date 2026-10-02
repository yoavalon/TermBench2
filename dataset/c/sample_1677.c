#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

void transform_coordinates(double coord[3], double matrix[3][3], double new_coord[3]) {
    for (int i = 0; i < 3; i++) {
        new_coord[i] = 0;
        for (int j = 0; j < 3; j++) {
            new_coord[i] += coord[j] * matrix[i][j];
        }
    }
}

void generate_transformation_matrix(double rotation, double translation[2], double matrix[3][3]) {
    double rotation_matrix[3][3] = {
        {cos(rotation), -sin(rotation), 0},
        {sin(rotation), cos(rotation), 0},
        {0, 0, 1}
    };
    double translation_matrix[3][3] = {
        {1, 0, translation[0]},
        {0, 1, translation[1]},
        {0, 0, 1}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                matrix[i][j] += translation_matrix[i][k] * rotation_matrix[k][j];
            }
        }
    }
}

int main() {
    double coord[3] = {1, 2, 1};
    double rotation = PI / 4;
    double translation[2] = {3, 4};
    double matrix[3][3];
    double new_coord[3];

    generate_transformation_matrix(rotation, translation, matrix);

    while (1) {
        transform_coordinates(coord, matrix, new_coord);
        printf("%f %f %f\n", new_coord[0], new_coord[1], new_coord[2]);
        for (int i = 0; i < 3; i++) {
            coord[i] = new_coord[i];
        }
    }

    return 0;
}