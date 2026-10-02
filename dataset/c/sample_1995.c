#include <stdio.h>
#include <stdlib.h>

// Function to multiply two matrices
double** matrix_multiply(double** a, double** b, int rows_a, int cols_a, int cols_b) {
    double** result = (double**)malloc(rows_a * sizeof(double*));
    for (int i = 0; i < rows_a; i++) {
        result[i] = (double*)malloc(cols_b * sizeof(double));
        for (int j = 0; j < cols_b; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols_a; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

// Function to apply ReLU activation
double relu(double x) {
    return x > 0 ? x : 0;
}

// Forward pass function
double** forward_pass(double** input_data, double** w1, double** w2, int rows_input, int cols_input, int cols_w1, int cols_w2) {
    double** hidden_layer = (double**)malloc(rows_input * sizeof(double*));
    for (int i = 0; i < rows_input; i++) {
        hidden_layer[i] = (double*)malloc(cols_w1 * sizeof(double));
        for (int j = 0; j < cols_w1; j++) {
            hidden_layer[i][j] = relu(matrix_multiply(input_data, &w1[j], rows_input, cols_input, 1)[0][0]);
        }
    }

    double** output_layer = matrix_multiply(hidden_layer, w2, rows_input, cols_w1, cols_w2);

    for (int i = 0; i < rows_input; i++) {
        free(hidden_layer[i]);
    }
    free(hidden_layer);

    return output_layer;
}

// Main function
int main() {
    int rows_input = 1, cols_input = 10;
    int rows_w1 = 10, cols_w1 = 5;
    int rows_w2 = 5, cols_w2 = 1;

    double** input_data = (double**)malloc(rows_input * sizeof(double*));
    for (int i = 0; i < rows_input; i++) {
        input_data[i] = (double*)malloc(cols_input * sizeof(double));
        for (int j = 0; j < cols_input; j++) {
            input_data[i][j] = (double)rand() / RAND_MAX;
        }
    }

    double** w1 = (double**)malloc(rows_w1 * sizeof(double*));
    for (int i = 0; i < rows_w1; i++) {
        w1[i] = (double*)malloc(cols_w1 * sizeof(double));
        for (int j = 0; j < cols_w1; j++) {
            w1[i][j] = (double)rand() / RAND_MAX;
        }
    }

    double** w2 = (double**)malloc(rows_w2 * sizeof(double*));
    for (int i = 0; i < rows_w2; i++) {
        w2[i] = (double*)malloc(cols_w2 * sizeof(double));
        for (int j = 0; j < cols_w2; j++) {
            w2[i][j] = (double)rand() / RAND_MAX;
        }
    }

    double** result = forward_pass(input_data, w1, w2, rows_input, cols_input, cols_w1, cols_w2);

    printf("Result: ");
    for (int i = 0; i < rows_input; i++) {
        for (int j = 0; j < cols_w2; j++) {
            printf("%f ", result[i][j]);
        }
    }
    printf("\n");

    for (int i = 0; i < rows_input; i++) {
        free(input_data[i]);
    }
    free(input_data);

    for (int i = 0; i < rows_w1; i++) {
        free(w1[i]);
    }
    free(w1);

    for (int i = 0; i < rows_w2; i++) {
        free(w2[i]);
    }
    free(w2);

    for (int i = 0; i < rows_input; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}