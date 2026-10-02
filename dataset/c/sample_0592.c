c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int size;
    int dimensions;
    double **particles;
    double **velocities;
    double **best_positions;
    double *best_scores;
    double *global_best;
    double global_best_score;
} Swarm;

typedef struct {
    Swarm *swarm;
    double (*objective_function)(double*);
} Optimization;

void swarm_init(Swarm *swarm, int size, int dimensions) {
    swarm->size = size;
    swarm->dimensions = dimensions;
    swarm->particles = (double **)malloc(size * sizeof(double *));
    swarm->velocities = (double **)malloc(size * sizeof(double *));
    swarm->best_positions = (double **)malloc(size * sizeof(double *));
    swarm->best_scores = (double *)malloc(size * sizeof(double));
    swarm->global_best = (double *)malloc(dimensions * sizeof(double));
    swarm->global_best_score = INFINITY;

    for (int i = 0; i < size; i++) {
        swarm->particles[i] = (double *)malloc(dimensions * sizeof(double));
        swarm->velocities[i] = (double *)malloc(dimensions * sizeof(double));
        swarm->best_positions[i] = (double *)malloc(dimensions * sizeof(double));
        for (int j = 0; j < dimensions; j++) {
            swarm->particles[i][j] = 0.0;
            swarm->velocities[i][j] = 0.0;
            swarm->best_positions[i][j] = 0.0;
        }
        swarm->best_scores[i] = INFINITY;
    }
    for (int j = 0; j < dimensions; j++) {
        swarm->global_best[j] = 0.0;
    }
}

void swarm_update_global_best(Swarm *swarm) {
    for (int i = 0; i < swarm->size; i++) {
        if (swarm->best_scores[i] < swarm->global_best_score) {
            swarm->global_best_score = swarm->best_scores[i];
            for (int j = 0; j < swarm->dimensions; j++) {
                swarm->global_best[j] = swarm->best_positions[i][j];
            }
        }
    }
}

void swarm_update_particles(Swarm *swarm) {
    for (int i = 0; i < swarm->size; i++) {
        for (int j = 0; j < swarm->dimensions; j++) {
            double r1 = 0.5;
            double r2 = 0.5;
            double cognitive = r1 * (swarm->best_positions[i][j] - swarm->particles[i][j]);
            double social = r2 * (swarm->global_best[j] - swarm->particles[i][j]);
            swarm->velocities[i][j] += cognitive + social;
            swarm->particles[i][j] += swarm->velocities[i][j];
        }
    }
}

void swarm_evaluate(Swarm *swarm, double (*objective_function)(double*)) {
    for (int i = 0; i < swarm->size; i++) {
        double score = objective_function(swarm->particles[i]);
        if (score < swarm->best_scores[i]) {
            swarm->best_scores[i] = score;
            for (int j = 0; j < swarm->dimensions; j++) {
                swarm->best_positions[i][j] = swarm->particles[i][j];
            }
        }
    }
    swarm_update_global_best(swarm);
}

void optimization_init(Optimization *optimization, Swarm *swarm, double (*objective_function)(double*)) {
    optimization->swarm = swarm;
    optimization->objective_function = objective_function;
}

void optimization_run(Optimization *optimization) {
    while (1) {
        swarm_update_particles(optimization->swarm);
        swarm_evaluate(optimization->swarm, optimization->objective_function);
    }
}

double objective_function(double *position) {
    double sum = 0.0;
    for (int i = 0; i < optimization->swarm->dimensions; i++) {
        sum += position[i] * position[i];
    }
    return sum;
}

void main() {
    int size = 30;
    int dimensions = 2;
    Swarm swarm;
    Optimization optimization;

    swarm_init(&swarm, size, dimensions);
    optimization_init(&optimization, &swarm, objective_function);
    optimization_run(&optimization);
}