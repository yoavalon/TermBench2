#include <stdio.h>
#include <math.h>

typedef struct {
    double **data;
    int rows;
    int cols;
} Matrix;

Matrix create_matrix(int rows, int cols) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix.data[i] = (double *)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            matrix.data[i][j] = 0;
        }
    }
    return matrix;
}

void free_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        free(matrix.data[i]);
    }
    free(matrix.data);
}

Matrix matrix_multiply(Matrix a, Matrix b) {
    Matrix result = create_matrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            for (int k = 0; k < b.rows; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}

void print_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            printf("%f ", matrix.data[i][j]);
        }
        printf("\n");
    }
}

Matrix rotation_matrix(char axis, double theta) {
    Matrix matrix = create_matrix(3, 3);
    if (axis == 'x') {
        matrix.data[0][0] = 1;
        matrix.data[1][1] = cos(theta);
        matrix.data[1][2] = -sin(theta);
        matrix.data[2][1] = sin(theta);
        matrix.data[2][2] = cos(theta);
    } else if (axis == 'y') {
        matrix.data[0][0] = cos(theta);
        matrix.data[0][2] = sin(theta);
        matrix.data[1][1] = 1;
        matrix.data[2][0] = -sin(theta);
        matrix.data[2][2] = cos(theta);
    } else if (axis == 'z') {
        matrix.data[0][0] = cos(theta);
        matrix.data[0][1] = -sin(theta);
        matrix.data[1][0] = sin(theta);
        matrix.data[1][1] = cos(theta);
        matrix.data[2][2] = 1;
    }
    return matrix;
}

double *transform_point(Matrix matrix, double *point) {
    Matrix point_matrix = create_matrix(3, 1);
    point_matrix.data[0][0] = point[0];
    point_matrix.data[1][0] = point[1];
    point_matrix.data[2][0] = point[2];
    Matrix transformed = matrix_multiply(matrix, point_matrix);
    double *result = (double *)malloc(3 * sizeof(double));
    result[0] = transformed.data[0][0];
    result[1] = transformed.data[1][0];
    result[2] = transformed.data[2][0];
    free_matrix(point_matrix);
    free_matrix(transformed);
    return result;
}

void main() {
    double point[] = {1, 2, 3};
    double theta = 0.785398;
    Matrix matrix_x = rotation_matrix('x', theta);
    Matrix matrix_y = rotation_matrix('y', theta);
    Matrix matrix_z = rotation_matrix('z', theta);
    double *transformed_x = transform_point(matrix_x, point);
    double *transformed_y = transform_point(matrix_y, point);
    double *transformed_z = transform_point(matrix_z, point);
    printf("Transformed by X-axis: %f %f %f\n", transformed_x[0], transformed_x[1], transformed_x[2]);
    printf("Transformed by Y-axis: %f %f %f\n", transformed_y[0], transformed_y[1], transformed_y[2]);
    printf("Transformed by Z-axis: %f %f %f\n", transformed_z[0], transformed_z[1], transformed_z[2]);
    free_matrix(matrix_x);
    free_matrix(matrix_y);
    free_matrix(matrix_z);
    free(transformed_x);
    free(transformed_y);
    free(transformed_z);
}