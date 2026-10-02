c
#include <stdio.h>
#include <math.h>

double** transform_coordinates(double* coords, double** matrix, int size) {
    double** result = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        result[i] = (double*)malloc(size * sizeof(double));
        result[i][0] = 0;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                result[i][0] += coords[k] * matrix[i][k];
            }
        }
    }
    return result;
}

double** generate_transformation_matrix(double angle_x, double angle_y, double angle_z) {
    double** Rx = (double**)malloc(3 * sizeof(double*));
    for (int i = 0; i < 3; i++) {
        Rx[i] = (double*)malloc(3 * sizeof(double));
    }
    Rx[0][0] = 1; Rx[0][1] = 0; Rx[0][2] = 0;
    Rx[1][0] = 0; Rx[1][1] = cos(angle_x); Rx[1][2] = -sin(angle_x);
    Rx[2][0] = 0; Rx[2][1] = sin(angle_x); Rx[2][2] = cos(angle_x);

    double** Ry = (double**)malloc(3 * sizeof(double*));
    for (int i = 0; i < 3; i++) {
        Ry[i] = (double*)malloc(3 * sizeof(double));
    }
    Ry[0][0] = cos(angle_y); Ry[0][1] = 0; Ry[0][2] = sin(angle_y);
    Ry[1][0] = 0; Ry[1][1] = 1; Ry[1][2] = 0;
    Ry[2][0] = -sin(angle_y); Ry[2][1] = 0; Ry[2][2] = cos(angle_y);

    double** Rz = (double**)malloc(3 * sizeof(double*));
    for (int i = 0; i < 3; i++) {
        Rz[i] = (double*)malloc(3 * sizeof(double));
    }
    Rz[0][0] = cos(angle_z); Rz[0][1] = -sin(angle_z); Rz[0][2] = 0;
    Rz[1][0] = sin(angle_z); Rz[1][1] = cos(angle_z); Rz[1][2] = 0;
    Rz[2][0] = 0; Rz[2][1] = 0; Rz[2][2] = 1;

    double** matrix = (double**)malloc(3 * sizeof(double*));
    for (int i = 0; i < 3; i++) {
        matrix[i] = (double*)malloc(3 * sizeof(double));
    }

    double** temp1 = (double**)malloc(3 * sizeof(double*));
    for (int i = 0; i < 3; i++) {
        temp1[i] = (double*)malloc(3 * sizeof(double));
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp1[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                temp1[i][j] += Rx[i][k] * Ry[k][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                matrix[i][j] += temp1[i][k] * Rz[k][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        free(Rx[i]);
        free(Ry[i]);
        free(Rz[i]);
        free(temp1[i]);
    }
    free(Rx);
    free(Ry);
    free(Rz);
    free(temp1);

    return matrix;
}

void main() {
    double coords[] = {1, 2, 3};
    double angles[] = {M_PI / 4, M_PI / 3, M_PI / 6};
    double** matrix = generate_transformation_matrix(angles[0], angles[1], angles[2]);
    double** new_coords = transform_coordinates(coords, matrix, 3);
    printf("%f %f %f\n", new_coords[0][0], new_coords[1][0], new_coords[2][0]);
    for (int i = 0; i < 3; i++) {
        free(matrix[i]);
        free(new_coords[i]);
    }
    free(matrix);
    free(new_coords);
}