c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 4
#define HIDDEN_SIZE 5
#define OUTPUT_SIZE 3

typedef struct {
    double **weights_input_hidden;
    double **weights_hidden_output;
    double *bias_hidden;
    double *bias_output;
} NeuralNetwork;

typedef struct {
    double **data;
} MatrixOperations;

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

NeuralNetwork* create_neural_network(int input_size, int hidden_size, int output_size) {
    NeuralNetwork *nn = (NeuralNetwork*)malloc(sizeof(NeuralNetwork));
    nn->weights_input_hidden = (double**)malloc(input_size * sizeof(double*));
    nn->weights_hidden_output = (double**)malloc(hidden_size * sizeof(double*));
    nn->bias_hidden = (double*)malloc(hidden_size * sizeof(double));
    nn->bias_output = (double*)malloc(output_size * sizeof(double));

    for (int i = 0; i < input_size; i++) {
        nn->weights_input_hidden[i] = (double*)malloc(hidden_size * sizeof(double));
        for (int j = 0; j < hidden_size; j++) {
            nn->weights_input_hidden[i][j] = (double)rand() / RAND_MAX;
        }
    }

    for (int i = 0; i < hidden_size; i++) {
        nn->weights_hidden_output[i] = (double*)malloc(output_size * sizeof(double));
        for (int j = 0; j < output_size; j++) {
            nn->weights_hidden_output[i][j] = (double)rand() / RAND_MAX;
        }
        nn->bias_hidden[i] = (double)rand() / RAND_MAX;
    }

    for (int i = 0; i < output_size; i++) {
        nn->bias_output[i] = (double)rand() / RAND_MAX;
    }

    return nn;
}

void free_neural_network(NeuralNetwork *nn) {
    for (int i = 0; i < INPUT_SIZE; i++) {
        free(nn->weights_input_hidden[i]);
    }
    free(nn->weights_input_hidden);

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        free(nn->weights_hidden_output[i]);
    }
    free(nn->weights_hidden_output);

    free(nn->bias_hidden);
    free(nn->bias_output);
    free(nn);
}

double** create_matrix(int rows, int cols) {
    double **matrix = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX;
        }
    }
    return matrix;
}

void free_matrix(double **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

double** add_identity(double **data, int size) {
    double **result = create_matrix(size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = data[i][j] + (i == j);
        }
    }
    return result;
}

double** transpose(double **data, int rows, int cols) {
    double **result = create_matrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = data[i][j];
        }
    }
    return result;
}

double** multiply_scalar(double **data, int rows, int cols, double scalar) {
    double **result = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

double** dot_product(double **a, int rows_a, int cols_a, double **b, int rows_b, int cols_b) {
    double **result = create_matrix(rows_a, cols_b);
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            result[i][j] = 0.0;
            for (int k = 0; k < cols_a; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

double* forward_pass(NeuralNetwork *nn, double *inputs) {
    double *hidden_layer_input = (double*)malloc(HIDDEN_SIZE * sizeof(double));
    double *hidden_layer_output = (double*)malloc(HIDDEN_SIZE * sizeof(double));
    double *output_layer_input = (double*)malloc(OUTPUT_SIZE * sizeof(double));
    double *output_layer_output = (double*)malloc(OUTPUT_SIZE * sizeof(double));

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        hidden_layer_input[i] = 0.0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            hidden_layer_input[i] += inputs[j] * nn->weights_input_hidden[j][i];
        }
        hidden_layer_input[i] += nn->bias_hidden[i];
        hidden_layer_output[i] = sigmoid(hidden_layer_input[i]);
    }

    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output_layer_input[i] = 0.0;
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            output_layer_input[i] += hidden_layer_output[j] * nn->weights_hidden_output[j][i];
        }
        output_layer_input[i] += nn->bias_output[i];
        output_layer_output[i] = sigmoid(output_layer_input[i]);
    }

    free(hidden_layer_input);
    free(hidden_layer_output);
    free(output_layer_input);

    return output_layer_output;
}

void main() {
    srand(0);
    NeuralNetwork *neural_net = create_neural_network(INPUT_SIZE, HIDDEN_SIZE, OUTPUT_SIZE);
    MatrixOperations *matrix_ops = (MatrixOperations*)malloc(sizeof(MatrixOperations));
    matrix_ops->data = create_matrix(INPUT_SIZE, INPUT_SIZE);

    double **modified_weights = add_identity(matrix_ops->data, INPUT_SIZE);
    modified_weights = transpose(modified_weights, INPUT_SIZE, INPUT_SIZE);
    modified_weights = multiply_scalar(modified_weights, INPUT_SIZE, INPUT_SIZE, 0.5);

    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            neural_net->weights_input_hidden[i][j] = modified_weights[i][j];
        }
    }

    double input_data[INPUT_SIZE];
    for (int i = 0; i < INPUT_SIZE; i++) {
        input_data[i] = (double)rand() / RAND_MAX;
    }

    double *output = forward_pass(neural_net, input_data);

    for (int i = 0; i < OUTPUT_SIZE; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");

    free_matrix(modified_weights, INPUT_SIZE);
    free_matrix(matrix_ops->data, INPUT_SIZE);
    free(matrix_ops);
    free_neural_network(neural_net);
    free(output);
}