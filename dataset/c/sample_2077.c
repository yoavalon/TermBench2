#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    double** data;
    int rows;
    int cols;
} Matrix;

Matrix create_matrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        mat.data[i] = (double*)malloc(cols * sizeof(double));
    }
    return mat;
}

void free_matrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        free(mat.data[i]);
    }
    free(mat.data);
}

Matrix dot(Matrix a, Matrix b) {
    Matrix result = create_matrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}

Matrix activation_function(Matrix x) {
    for (int i = 0; i < x.rows; i++) {
        for (int j = 0; j < x.cols; j++) {
            x.data[i][j] = MAX(0, x.data[i][j]);
        }
    }
    return x;
}

typedef struct {
    Matrix data;
} MatrixOperations;

MatrixOperations create_matrix_operations(Matrix data) {
    MatrixOperations mo;
    mo.data = data;
    return mo;
}

Matrix forward_pass(MatrixOperations* mo, Matrix weights) {
    return dot(mo->data, weights);
}

Matrix process(MatrixOperations* mo, Matrix weights) {
    Matrix intermediate = forward_pass(mo, weights);
    return activation_function(intermediate);
}

typedef struct {
    MatrixOperations** layers;
    int num_layers;
} NeuralNetwork;

NeuralNetwork create_neural_network(int num_layers) {
    NeuralNetwork nn;
    nn.num_layers = num_layers;
    nn.layers = (MatrixOperations**)malloc(num_layers * sizeof(MatrixOperations*));
    return nn;
}

void free_neural_network(NeuralNetwork nn) {
    for (int i = 0; i < nn.num_layers; i++) {
        free_matrix_operations(*nn.layers[i]);
        free(nn.layers[i]);
    }
    free(nn.layers);
}

Matrix generate_random_data(int rows, int cols) {
    Matrix mat = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat.data[i][j] = ((double)rand() / RAND_MAX);
        }
    }
    return mat;
}

Matrix predict(NeuralNetwork* nn, Matrix input_data) {
    Matrix result = input_data;
    for (int i = 0; i < nn->num_layers; i++) {
        result = process(nn->layers[i], nn->layers[i]->data);
    }
    return result;
}

int main() {
    srand(time(NULL));
    int input_shape[] = {10, 5};
    int weight_shape[] = {5, 3};
    int num_layers = 3;
    Matrix input_data = generate_random_data(input_shape[0], input_shape[1]);
    Matrix weights = generate_random_data(weight_shape[0], weight_shape[1]);
    NeuralNetwork nn = create_neural_network(num_layers);
    for (int i = 0; i < num_layers; i++) {
        Matrix random_data = generate_random_data(weight_shape[0], weight_shape[1]);
        nn.layers[i] = (MatrixOperations*)malloc(sizeof(MatrixOperations));
        *nn.layers[i] = create_matrix_operations(random_data);
    }
    Matrix output = predict(&nn, input_data);
    for (int i = 0; i < output.rows; i++) {
        for (int j = 0; j < output.cols; j++) {
            printf("%f ", output.data[i][j]);
        }
        printf("\n");
    }
    free_matrix(input_data);
    free_matrix(weights);
    free_neural_network(nn);
    return 0;
}