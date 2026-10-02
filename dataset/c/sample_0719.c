#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 100
#define NUM_PARTICLES 10

double random_double() {
    return ((double)rand() / (double)RAND_MAX);
}

double fitness(double x) {
    return x * x;
}

double min(double arr[], int size, int (*func)(double)) {
    double min_val = func(arr[0]);
    for (int i = 1; i < size; i++) {
        if (func(arr[i]) < min_val) {
            min_val = func(arr[i]);
        }
    }
    return min_val;
}

double* optimize(double positions[], double velocities[], double personal_best[], double global_best, int iteration) {
    if (iteration >= MAX_ITERATIONS) {
        return &global_best;
    }
    double new_positions[NUM_PARTICLES];
    double new_velocities[NUM_PARTICLES];
    for (int i = 0; i < NUM_PARTICLES; i++) {
        double r1 = random_double();
        double r2 = random_double();
        new_velocities[i] = velocities[i] + 2 * r1 * (personal_best[i] - positions[i]) + 2 * r2 * (global_best - positions[i]);
        new_positions[i] = positions[i] + new_velocities[i];
    }
    double new_global_best = min(new_positions, NUM_PARTICLES, fitness);
    return optimize(new_positions, new_velocities, personal_best, new_global_best, iteration + 1);
}

int main() {
    double positions[NUM_PARTICLES];
    double velocities[NUM_PARTICLES];
    double personal_best[NUM_PARTICLES];
    double global_best;
    for (int i = 0; i < NUM_PARTICLES; i++) {
        positions[i] = (double)rand() / RAND_MAX * 20 - 10;
        velocities[i] = 0.0;
        personal_best[i] = positions[i];
    }
    global_best = min(positions, NUM_PARTICLES, fitness);
    optimize(positions, velocities, personal_best, global_best, 0);
    return 0;
}