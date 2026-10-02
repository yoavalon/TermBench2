#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double **matrix;
    int rows;
    int cols;
} Matrix;

typedef struct {
    Matrix *matrix;
} MatrixOperations;

typedef struct {
    MatrixOperations **layers;
    int num_layers;
} NeuralNetwork;

typedef struct {
    NeuralNetwork *neural_network;
    Matrix *input_data;
} RecursiveProcess;

Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix->matrix[i] = (double *)malloc(cols * sizeof(double));
    }
    return matrix;
}

void free_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

MatrixOperations *create_matrix_operations(Matrix *matrix) {
    MatrixOperations *operations = (MatrixOperations *)malloc(sizeof(MatrixOperations));
    operations->matrix = matrix;
    return operations;
}

void free_matrix_operations(MatrixOperations *operations) {
    free_matrix(operations->matrix);
    free(operations);
}

NeuralNetwork *create_neural_network(MatrixOperations **layers, int num_layers) {
    NeuralNetwork *network = (NeuralNetwork *)malloc(sizeof(NeuralNetwork));
    network->layers = layers;
    network->num_layers = num_layers;
    return network;
}

void free_neural_network(NeuralNetwork *network) {
    for (int i = 0; i < network->num_layers; i++) {
        free_matrix_operations(network->layers[i]);
    }
    free(network->layers);
    free(network);
}

RecursiveProcess *create_recursive_process(NeuralNetwork *neural_network, Matrix *input_data) {
    RecursiveProcess *process = (RecursiveProcess *)malloc(sizeof(RecursiveProcess));
    process->neural_network = neural_network;
    process->input_data = input_data;
    return process;
}

void free_recursive_process(RecursiveProcess *process) {
    free_neural_network(process->neural_network);
    free_matrix(process->input_data);
    free(process);
}

Matrix *multiply_matrices(Matrix *a, Matrix *b) {
    if (a->cols != b->rows) {
        fprintf(stderr, "Matrix dimensions do not match for multiplication.\n");
        exit(EXIT_FAILURE);
    }
    Matrix *result = create_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            result->matrix[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                result->matrix[i][j] += a->matrix[i][k] * b->matrix[k][j];
            }
        }
    }
    return result;
}

Matrix *add_matrices(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        fprintf(stderr, "Matrix dimensions do not match for addition.\n");
        exit(EXIT_FAILURE);
    }
    Matrix *result = create_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }
    return result;
}

Matrix *forward_pass(NeuralNetwork *network, Matrix *input_data) {
    Matrix *current_data = input_data;
    for (int i = 0; i < network->num_layers; i++) {
        Matrix *result = multiply_matrices(network->layers[i]->matrix, current_data);
        free_matrix(current_data);
        current_data = result;
    }
    return current_data;
}

void process(RecursiveProcess *process, Matrix *current_data) {
    Matrix *output_data = forward_pass(process->neural_network, current_data);
    free_matrix(current_data);
    process(process, output_data);
}

int main() {
    Matrix *matrix1 = create_matrix(2, 2);
    matrix1->matrix[0][0] = 0.5; matrix1->matrix[0][1] = 0.2;
    matrix1->matrix[1][0] = 0.3; matrix1->matrix[1][1] = 0.7;
    Matrix *matrix2 = create_matrix(2, 2);
    matrix2->matrix[0][0] = 0.1; matrix2->matrix[0][1] = 0.4;
    matrix2->matrix[1][0] = 0.9; matrix2->matrix[1][1] = 0.5;
    MatrixOperations *layer1 = create_matrix_operations(matrix1);
    MatrixOperations *layer2 = create_matrix_operations(matrix2);
    MatrixOperations *layers[] = {layer1, layer2};
    NeuralNetwork *neural_network = create_neural_network(layers, 2);
    Matrix *input_data = create_matrix(2, 1);
    input_data->matrix[0][0] = 1; input_data->matrix[1][0] = 1;
    RecursiveProcess *recursive_process = create_recursive_process(neural_network, input_data);
    process(recursive_process, input_data);
    free_recursive_process(recursive_process);
    return 0;
}