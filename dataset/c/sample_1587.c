#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double** create_matrix(int rows, int cols) {
    double** matrix = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

void free_matrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

double** multiply_matrices(double** a, double** b, int rows, int cols, int inner) {
    double** result = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < inner; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

double** invert_matrix(double** a, int size) {
    double** result = create_matrix(size, size);
    double** temp = create_matrix(size, size);
    double** adj = create_matrix(size, size);
    double** cof = create_matrix(size, size);
    double det = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp[i][j] = a[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cof[i][j] = ((i + j) % 2 == 0) ? 1 : -1;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            double minor = 1;
            for (int k = 0; k < size; k++) {
                if (k != i) {
                    minor = 1;
                    for (int l = 0; l < size; l++) {
                        if (l != j) {
                            minor *= temp[k][l];
                        }
                    }
                    adj[i][j] += cof[i][k] * minor;
                }
            }
        }
    }

    for (int i = 0; i < size; i++) {
        det += a[0][i] * adj[0][i];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = adj[i][j] / det;
        }
    }

    free_matrix(temp, size);
    free_matrix(adj, size);
    free_matrix(cof, size);

    return result;
}

void print_matrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transform_coordinates() {
    while (1) {
        double** a = create_matrix(3, 3);
        double** b = create_matrix(3, 1);
        double** x;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a[i][j] = (double)rand() / RAND_MAX;
            }
            b[i][0] = (double)rand() / RAND_MAX;
        }

        double** a_inv = invert_matrix(a, 3);
        x = multiply_matrices(a_inv, b, 3, 1, 3);

        print_matrix(x, 3, 1);

        free_matrix(a, 3);
        free_matrix(b, 3);
        free_matrix(a_inv, 3);
        free_matrix(x, 3);
    }
}

int main() {
    srand(time(0));
    transform_coordinates();
    return 0;
}