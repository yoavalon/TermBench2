#include <stdio.h>
#include <math.h>

double dot_product(double a[], double b[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

void matrix_multiply(double a[3][3], double b[3][3], double result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = dot_product(a[i], b[j], 3);
        }
    }
}

void transform_coordinates(double coords[3][3], double matrix[3][3], double transformed[3][3]) {
    matrix_multiply(coords, matrix, transformed);
}

void generate_transformation_matrix(double angle_x, double angle_y, double angle_z, double matrix[3][3]) {
    double c_x = cos(angle_x), s_x = sin(angle_x);
    double c_y = cos(angle_y), s_y = sin(angle_y);
    double c_z = cos(angle_z), s_z = sin(angle_z);
    double rot_x[3][3] = {{1, 0, 0}, {0, c_x, -s_x}, {0, s_x, c_x}};
    double rot_y[3][3] = {{c_y, 0, s_y}, {0, 1, 0}, {-s_y, 0, c_y}};
    double rot_z[3][3] = {{c_z, -s_z, 0}, {s_z, c_z, 0}, {0, 0, 1}};
    double temp[3][3];
    matrix_multiply(rot_y, rot_x, temp);
    matrix_multiply(rot_z, temp, matrix);
}

void print_matrix(double matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double initial_coords[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double angles[3] = {45, 30, 60};
    for (int i = 0; i < 3; i++) {
        angles[i] = angles[i] * M_PI / 180;
    }
    double transformation_matrix[3][3];
    generate_transformation_matrix(angles[0], angles[1], angles[2], transformation_matrix);
    double transformed_coords[3][3];
    transform_coordinates(initial_coords, transformation_matrix, transformed_coords);
    print_matrix(transformed_coords);
    return 0;
}