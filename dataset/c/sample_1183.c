#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int size;
    int dimensions;
    double **positions;
    double **velocities;
    double **best_positions;
    double *best_scores;
    double *global_best_position;
    double global_best_score;
} Swarm;

void initialize_swarm(Swarm *swarm, int size, int dimensions) {
    swarm->size = size;
    swarm->dimensions = dimensions;
    swarm->positions = (double **)malloc(size * sizeof(double *));
    swarm->velocities = (double **)malloc(size * sizeof(double *));
    swarm->best_positions = (double **)malloc(size * sizeof(double *));
    swarm->best_scores = (double *)malloc(size * sizeof(double));
    swarm->global_best_position = (double *)malloc(dimensions * sizeof(double));
    swarm->global_best_score = INFINITY;

    for (int i = 0; i < size; i++) {
        swarm->positions[i] = (double *)malloc(dimensions * sizeof(double));
        swarm->velocities[i] = (double *)malloc(dimensions * sizeof(double));
        swarm->best_positions[i] = (double *)malloc(dimensions * sizeof(double));
        for (int j = 0; j < dimensions; j++) {
            swarm->positions[i][j] = 0.0;
            swarm->velocities[i][j] = 0.0;
            swarm->best_positions[i][j] = 0.0;
        }
        swarm->best_scores[i] = INFINITY;
    }
    for (int j = 0; j < dimensions; j++) {
        swarm->global_best_position[j] = 0.0;
    }
}

void update_global_best(Swarm *swarm) {
    for (int i = 0; i < swarm->size; i++) {
        double score = 0.0;
        for (int j = 0; j < swarm->dimensions; j++) {
            score += swarm->best_positions[i][j] * swarm->best_positions[i][j];
        }
        if (score < swarm->global_best_score) {
            swarm->global_best_score = score;
            for (int j = 0; j < swarm->dimensions; j++) {
                swarm->global_best_position[j] = swarm->best_positions[i][j];
            }
        }
    }
}

double evaluate(double *position, int dimensions) {
    double score = 0.0;
    for (int i = 0; i < dimensions; i++) {
        score += position[i] * position[i];
    }
    return score;
}

void update_particles(Swarm *swarm) {
    for (int i = 0; i < swarm->size; i++) {
        double r1 = 0.5, r2 = 0.5;
        double c1 = 2.0, c2 = 2.0;
        for (int j = 0; j < swarm->dimensions; j++) {
            swarm->velocities[i][j] = 0.7 * swarm->velocities[i][j] + c1 * r1 * (swarm->best_positions[i][j] - swarm->positions[i][j]) + c2 * r2 * (swarm->global_best_position[j] - swarm->positions[i][j]);
            swarm->positions[i][j] += swarm->velocities[i][j];
        }
        swarm->best_scores[i] = evaluate(swarm->positions[i], swarm->dimensions);
        if (swarm->best_scores[i] < swarm->global_best_score) {
            for (int j = 0; j < swarm->dimensions; j++) {
                swarm->best_positions[i][j] = swarm->positions[i][j];
            }
        }
    }
}

void iterate(Swarm *swarm) {
    update_global_best(swarm);
    update_particles(swarm);
    iterate(swarm);
}

void free_swarm(Swarm *swarm) {
    for (int i = 0; i < swarm->size; i++) {
        free(swarm->positions[i]);
        free(swarm->velocities[i]);
        free(swarm->best_positions[i]);
    }
    free(swarm->positions);
    free(swarm->velocities);
    free(swarm->best_positions);
    free(swarm->best_scores);
    free(swarm->global_best_position);
}

int main() {
    Swarm swarm;
    initialize_swarm(&swarm, 30, 2);
    iterate(&swarm);
    free_swarm(&swarm);
    return 0;
}