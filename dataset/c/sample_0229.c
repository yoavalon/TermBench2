#include <stdio.h>
#include <math.h>

double matrix_multiply(double A[4][4], double B[4][1], double result[4][1]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 1; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result[0][0];
}

void translate_point(double point[3], double translation[3], double transformed_point[3]) {
    double translation_matrix[4][4] = {
        {1, 0, 0, translation[0]},
        {0, 1, 0, translation[1]},
        {0, 0, 1, translation[2]},
        {0, 0, 0, 1}
    };
    double point_matrix[4][1] = {
        {point[0]},
        {point[1]},
        {point[2]},
        {1}
    };
    double result[4][1];
    matrix_multiply(translation_matrix, point_matrix, result);
    transformed_point[0] = result[0][0];
    transformed_point[1] = result[1][0];
    transformed_point[2] = result[2][0];
}

void rotate_point(double point[3], double angle, char axis, double transformed_point[3]) {
    double rotation_matrix[4][4];
    if (axis == 'x') {
        rotation_matrix[0][0] = 1; rotation_matrix[0][1] = 0; rotation_matrix[0][2] = 0; rotation_matrix[0][3] = 0;
        rotation_matrix[1][0] = 0; rotation_matrix[1][1] = cos(angle); rotation_matrix[1][2] = -sin(angle); rotation_matrix[1][3] = 0;
        rotation_matrix[2][0] = 0; rotation_matrix[2][1] = sin(angle); rotation_matrix[2][2] = cos(angle); rotation_matrix[2][3] = 0;
        rotation_matrix[3][0] = 0; rotation_matrix[3][1] = 0; rotation_matrix[3][2] = 0; rotation_matrix[3][3] = 1;
    } else if (axis == 'y') {
        rotation_matrix[0][0] = cos(angle); rotation_matrix[0][1] = 0; rotation_matrix[0][2] = sin(angle); rotation_matrix[0][3] = 0;
        rotation_matrix[1][0] = 0; rotation_matrix[1][1] = 1; rotation_matrix[1][2] = 0; rotation_matrix[1][3] = 0;
        rotation_matrix[2][0] = -sin(angle); rotation_matrix[2][1] = 0; rotation_matrix[2][2] = cos(angle); rotation_matrix[2][3] = 0;
        rotation_matrix[3][0] = 0; rotation_matrix[3][1] = 0; rotation_matrix[3][2] = 0; rotation_matrix[3][3] = 1;
    } else if (axis == 'z') {
        rotation_matrix[0][0] = cos(angle); rotation_matrix[0][1] = -sin(angle); rotation_matrix[0][2] = 0; rotation_matrix[0][3] = 0;
        rotation_matrix[1][0] = sin(angle); rotation_matrix[1][1] = cos(angle); rotation_matrix[1][2] = 0; rotation_matrix[1][3] = 0;
        rotation_matrix[2][0] = 0; rotation_matrix[2][1] = 0; rotation_matrix[2][2] = 1; rotation_matrix[2][3] = 0;
        rotation_matrix[3][0] = 0; rotation_matrix[3][1] = 0; rotation_matrix[3][2] = 0; rotation_matrix[3][3] = 1;
    }
    double point_matrix[4][1] = {
        {point[0]},
        {point[1]},
        {point[2]},
        {1}
    };
    double result[4][1];
    matrix_multiply(rotation_matrix, point_matrix, result);
    transformed_point[0] = result[0][0];
    transformed_point[1] = result[1][0];
    transformed_point[2] = result[2][0];
}

void scale_point(double point[3], double scale, double transformed_point[3]) {
    double scaling_matrix[4][4] = {
        {scale, 0, 0, 0},
        {0, scale, 0, 0},
        {0, 0, scale, 0},
        {0, 0, 0, 1}
    };
    double point_matrix[4][1] = {
        {point[0]},
        {point[1]},
        {point[2]},
        {1}
    };
    double result[4][1];
    matrix_multiply(scaling_matrix, point_matrix, result);
    transformed_point[0] = result[0][0];
    transformed_point[1] = result[1][0];
    transformed_point[2] = result[2][0];
}

int main() {
    double point[3] = {1, 2, 3};
    double translation[3] = {1, 1, 1};
    double angle = 30 * (3.14159 / 180);
    double scale_factor = 2;
    double transformed_point[3];

    translate_point(point, translation, transformed_point);
    rotate_point(transformed_point, angle, 'z', transformed_point);
    scale_point(transformed_point, scale_factor, transformed_point);

    printf("%f %f %f\n", transformed_point[0], transformed_point[1], transformed_point[2]);

    return 0;
}