c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 3
#define COLS 1

typedef struct {
    double data[ROWS][COLS];
} MatrixOp;

void matrix_init(MatrixOp *mat, double data[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            mat->data[i][j] = data[i][j];
        }
    }
}

MatrixOp matrix_multiply(MatrixOp *a, MatrixOp *b) {
    MatrixOp result;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < ROWS; k++) {
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result;
}

MatrixOp matrix_add(MatrixOp *a, MatrixOp *b) {
    MatrixOp result;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result.data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return result;
}

MatrixOp matrix_sigmoid(MatrixOp *mat) {
    MatrixOp result;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result.data[i][j] = 1 / (1 + exp(-mat->data[i][j]));
        }
    }
    return result;
}

MatrixOp matrix_relu(MatrixOp *mat) {
    MatrixOp result;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result.data[i][j] = fmax(0, mat->data[i][j]);
        }
    }
    return result;
}

typedef struct {
    MatrixOp weights;
    MatrixOp (*activation)(MatrixOp*);
} Layer;

typedef struct {
    Layer layers[2];
} NeuralNetwork;

void neural_network_init(NeuralNetwork *net, MatrixOp weights1, MatrixOp weights2) {
    net->layers[0].weights = weights1;
    net->layers[0].activation = matrix_sigmoid;
    net->layers[1].weights = weights2;
    net->layers[1].activation = matrix_relu;
}

MatrixOp neural_network_forward_pass(NeuralNetwork *net, MatrixOp input_data) {
    MatrixOp result = input_data;
    for (int i = 0; i < 2; i++) {
        MatrixOp weighted_input = matrix_multiply(&(net->layers[i].weights), &result);
        result = net->layers[i].activation(&weighted_input);
    }
    return result;
}

void main() {
    srand(0);
    double input_data_init[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            input_data_init[i][j] = (double)rand() / RAND_MAX;
        }
    }
    MatrixOp input_data;
    matrix_init(&input_data, input_data_init);

    double weights1_init[2][3];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            weights1_init[i][j] = (double)rand() / RAND_MAX;
        }
    }
    MatrixOp weights1;
    matrix_init(&weights1, weights1_init);

    double weights2_init[1][2];
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 2; j++) {
            weights2_init[i][j] = (double)rand() / RAND_MAX;
        }
    }
    MatrixOp weights2;
    matrix_init(&weights2, weights2_init);

    NeuralNetwork network;
    neural_network_init(&network, weights1, weights2);

    MatrixOp output = neural_network_forward_pass(&network, input_data);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%f ", output.data[i][j]);
        }
    }
    printf("\n");
}