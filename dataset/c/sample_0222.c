#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    double **data;
    int rows;
    int cols;
} Matrix;

typedef struct {
    Matrix data;
} MatrixOps;

typedef struct {
    MatrixOps **layers;
    int num_layers;
} Network;

typedef struct {
    Network network;
} BoundaryConditions;

void matrix_init(Matrix *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        m->data[i] = (double *)malloc(cols * sizeof(double));
    }
}

void matrix_free(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
}

void matrix_copy(Matrix *dest, const Matrix *src) {
    dest->rows = src->rows;
    dest->cols = src->cols;
    dest->data = (double **)malloc(dest->rows * sizeof(double *));
    for (int i = 0; i < dest->rows; i++) {
        dest->data[i] = (double *)malloc(dest->cols * sizeof(double));
        for (int j = 0; j < dest->cols; j++) {
            dest->data[i][j] = src->data[i][j];
        }
    }
}

void matrix_dot(const Matrix *a, const Matrix *b, Matrix *c) {
    c->rows = a->rows;
    c->cols = b->cols;
    c->data = (double **)malloc(c->rows * sizeof(double *));
    for (int i = 0; i < c->rows; i++) {
        c->data[i] = (double *)malloc(c->cols * sizeof(double));
        for (int j = 0; j < c->cols; j++) {
            c->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                c->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
}

void matrixops_init(MatrixOps *mo, int rows, int cols) {
    matrix_init(&mo->data, rows, cols);
}

void matrixops_free(MatrixOps *mo) {
    matrix_free(&mo->data);
}

Matrix matrixops_forward_pass(const MatrixOps *mo, const Matrix *weights) {
    Matrix result;
    matrix_dot(&mo->data, weights, &result);
    return result;
}

void network_init(Network *net, int num_layers) {
    net->num_layers = num_layers;
    net->layers = (MatrixOps **)malloc(num_layers * sizeof(MatrixOps *));
}

void network_free(Network *net) {
    for (int i = 0; i < net->num_layers; i++) {
        matrixops_free(net->layers[i]);
        free(net->layers[i]);
    }
    free(net->layers);
}

Matrix network_compute(const Network *net, const Matrix *input_data) {
    Matrix current = *input_data;
    for (int i = 0; i < net->num_layers; i++) {
        Matrix result = matrixops_forward_pass(net->layers[i], &current);
        matrix_free(&current);
        current = result;
    }
    return current;
}

void boundaryconditions_init(BoundaryConditions *bc, Network *network) {
    bc->network = *network;
}

void boundaryconditions_free(BoundaryConditions *bc) {
    network_free(&bc->network);
}

bool boundaryconditions_validate(const BoundaryConditions *bc, const Matrix *input_data, const Matrix *expected_output) {
    Matrix output = network_compute(&bc->network, input_data);
    bool result = true;
    for (int i = 0; i < output.rows && result; i++) {
        for (int j = 0; j < output.cols && result; j++) {
            result = fabs(output.data[i][j] - expected_output->data[i][j]) < 1e-6;
        }
    }
    matrix_free(&output);
    return result;
}

int main() {
    Matrix data, weights1, weights2, input_data, expected_output;
    MatrixOps *layer1, *layer2, *layer3;
    Network network;
    BoundaryConditions boundary_conditions;

    matrix_init(&data, 2, 2);
    data.data[0][0] = 1; data.data[0][1] = 2;
    data.data[1][0] = 3; data.data[1][1] = 4;

    matrix_init(&weights1, 2, 2);
    weights1.data[0][0] = 0.1; weights1.data[0][1] = 0.2;
    weights1.data[1][0] = 0.3; weights1.data[1][1] = 0.4;

    matrix_init(&weights2, 2, 2);
    weights2.data[0][0] = 0.5; weights2.data[0][1] = 0.6;
    weights2.data[1][0] = 0.7; weights2.data[1][1] = 0.8;

    matrix_init(&input_data, 1, 2);
    input_data.data[0][0] = 1; input_data.data[0][1] = 1;

    matrix_init(&expected_output, 1, 2);
    expected_output.data[0][0] = 0.7; expected_output.data[0][1] = 0.8;

    layer1 = (MatrixOps *)malloc(sizeof(MatrixOps));
    matrixops_init(layer1, 2, 2);
    matrix_copy(&layer1->data, &data);

    layer2 = (MatrixOps *)malloc(sizeof(MatrixOps));
    matrixops_init(layer2, 2, 2);
    matrix_copy(&layer2->data, &weights1);

    layer3 = (MatrixOps *)malloc(sizeof(MatrixOps));
    matrixops_init(layer3, 2, 2);
    matrix_copy(&layer3->data, &weights2);

    network_init(&network, 3);
    network.layers[0] = layer1;
    network.layers[1] = layer2;
    network.layers[2] = layer3;

    boundaryconditions_init(&boundary_conditions, &network);

    bool result = boundaryconditions_validate(&boundary_conditions, &input_data, &expected_output);

    printf("%d\n", result);

    boundaryconditions_free(&boundary_conditions);
    network_free(&network);
    matrix_free(&data);
    matrix_free(&weights1);
    matrix_free(&weights2);
    matrix_free(&input_data);
    matrix_free(&expected_output);

    return 0;
}