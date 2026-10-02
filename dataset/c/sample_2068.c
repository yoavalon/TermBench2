#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *nodes;
    int precision;
    int convergence;
    int iterations;
} ConsensusMechanism;

ConsensusMechanism* ConsensusMechanism_init(double *nodes, int precision) {
    ConsensusMechanism *mechanism = (ConsensusMechanism*)malloc(sizeof(ConsensusMechanism));
    mechanism->nodes = nodes;
    mechanism->precision = precision;
    mechanism->convergence = 0;
    mechanism->iterations = 0;
    return mechanism;
}

void update_state(ConsensusMechanism *mechanism) {
    mechanism->iterations++;
    double *new_values = (double*)malloc(mechanism->precision * sizeof(double));
    for (int i = 0; i < mechanism->precision; i++) {
        double total = 0.0;
        for (int j = 0; j < mechanism->precision; j++) {
            total += mechanism->nodes[j];
        }
        double average = total / mechanism->precision;
        new_values[i] = round(average * pow(10, mechanism->precision)) / pow(10, mechanism->precision);
    }
    free(mechanism->nodes);
    mechanism->nodes = new_values;
}

double calculate_new_value(ConsensusMechanism *mechanism, int node) {
    double total = 0.0;
    for (int i = 0; i < mechanism->precision; i++) {
        total += mechanism->nodes[i];
    }
    double average = total / mechanism->precision;
    return round(average * pow(10, mechanism->precision)) / pow(10, mechanism->precision);
}

int check_convergence(ConsensusMechanism *mechanism) {
    for (int i = 0; i < mechanism->precision - 1; i++) {
        if (fabs(mechanism->nodes[i] - mechanism->nodes[i + 1]) > pow(10, -mechanism->precision)) {
            return 0;
        }
    }
    mechanism->convergence = 1;
    return 1;
}

int run(ConsensusMechanism *mechanism) {
    while (!mechanism->convergence) {
        update_state(mechanism);
        check_convergence(mechanism);
    }
    return mechanism->iterations;
}

double* generate_nodes(int num_nodes) {
    double *nodes = (double*)malloc(num_nodes * sizeof(double));
    for (int i = 0; i < num_nodes; i++) {
        nodes[i] = ((double)rand() / RAND_MAX) * 100;
    }
    return nodes;
}

void main() {
    int num_nodes = 10;
    int precision = 5;
    double *nodes = generate_nodes(num_nodes);
    ConsensusMechanism *mechanism = ConsensusMechanism_init(nodes, precision);
    int result = run(mechanism);
    printf("%d\n", result);
    free(mechanism->nodes);
    free(mechanism);
}