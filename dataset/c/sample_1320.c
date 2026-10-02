#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_supply_chain(int *data, int size, double *mutated_data) {
    for (int i = 0; i < size; i++) {
        double mutation_factor = ((double)rand() / RAND_MAX) * 0.2 + 0.9;
        mutated_data[i] = data[i] * mutation_factor;
    }
}

void optimize_logistics(double *data, int size, double *optimized_data) {
    for (int i = 0; i < size; i++) {
        if (data[i] > 100) {
            optimized_data[i] = data[i] * 0.95;
        } else {
            optimized_data[i] = data[i] * 1.05;
        }
    }
}

void main() {
    srand(time(NULL));
    int initial_data[10];
    double mutated_data[10];
    double optimized_data[10];

    for (int i = 0; i < 10; i++) {
        initial_data[i] = rand() % 101 + 50;
    }

    generate_supply_chain(initial_data, 10, mutated_data);
    optimize_logistics(mutated_data, 10, optimized_data);

    for (int i = 0; i < 10; i++) {
        printf("%f ", optimized_data[i]);
    }
}