#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef struct {
    int size;
    int dimensions;
    double** positions;
    double** velocities;
    double** best_positions;
    double* best_scores;
} Swarm;

Swarm* create_swarm(int size, int dimensions) {
    Swarm* swarm = (Swarm*)malloc(sizeof(Swarm));
    swarm->size = size;
    swarm->dimensions = dimensions;
    swarm->positions = (double**)malloc(size * sizeof(double*));
    swarm->velocities = (double**)malloc(size * sizeof(double*));
    swarm->best_positions = (double**)malloc(size * sizeof(double*));
    swarm->best_scores = (double*)malloc(size * sizeof(double));

    for (int i = 0; i < size; i++) {
        swarm->positions[i] = (double*)calloc(dimensions, sizeof(double));
        swarm->velocities[i] = (double*)calloc(dimensions, sizeof(double));
        swarm->best_positions[i] = (double*)calloc(dimensions, sizeof(double));
        swarm->best_scores[i] = INFINITY;
    }
    return swarm;
}

void update_best_positions(Swarm* swarm, double* scores) {
    for (int i = 0; i < swarm->size; i++) {
        if (scores[i] < swarm->best_scores[i]) {
            swarm->best_scores[i] = scores[i];
            for (int j = 0; j < swarm->dimensions; j++) {
                swarm->best_positions[i][j] = swarm->positions[i][j];
            }
        }
    }
}

void update_velocities(Swarm* swarm, double* global_best_position, double w, double c1, double c2) {
    for (int i = 0; i < swarm->size; i++) {
        for (int j = 0; j < swarm->dimensions; j++) {
            double r1 = 0.5, r2 = 0.5;
            swarm->velocities[i][j] = w * swarm->velocities[i][j] + c1 * r1 * (swarm->best_positions[i][j] - swarm->positions[i][j]) + c2 * r2 * (global_best_position[j] - swarm->positions[i][j]);
        }
    }
}

void update_positions(Swarm* swarm) {
    for (int i = 0; i < swarm->size; i++) {
        for (int j = 0; j < swarm->dimensions; j++) {
            swarm->positions[i][j] += swarm->velocities[i][j];
        }
    }
}

double fitness_function(double* position, int dimensions) {
    double sum = 0.0;
    for (int i = 0; i < dimensions; i++) {
        sum += position[i] * position[i];
    }
    return sum;
}

void destroy_swarm(Swarm* swarm) {
    for (int i = 0; i < swarm->size; i++) {
        free(swarm->positions[i]);
        free(swarm->velocities[i]);
        free(swarm->best_positions[i]);
    }
    free(swarm->positions);
    free(swarm->velocities);
    free(swarm->best_positions);
    free(swarm->best_scores);
    free(swarm);
}

void main() {
    int swarm_size = 30;
    int dimensions = 2;
    int max_iterations = 100;
    Swarm* swarm = create_swarm(swarm_size, dimensions);
    double scores[swarm_size];

    for (int iteration = 0; iteration < max_iterations; iteration++) {
        for (int i = 0; i < swarm_size; i++) {
            scores[i] = fitness_function(swarm->positions[i], dimensions);
        }
        int global_best_index = 0;
        double global_best_score = scores[0];
        for (int i = 1; i < swarm_size; i++) {
            if (scores[i] < global_best_score) {
                global_best_score = scores[i];
                global_best_index = i;
            }
        }
        double* global_best_position = swarm->positions[global_best_index];
        update_best_positions(swarm, scores);
        update_velocities(swarm, global_best_position, 0.7, 1.5, 1.5);
        update_positions(swarm);
    }

    double best_score = INFINITY;
    int best_index = 0;
    for (int i = 0; i < swarm_size; i++) {
        if (swarm->best_scores[i] < best_score) {
            best_score = swarm->best_scores[i];
            best_index = i;
        }
    }
    printf("Best score: %f\n", best_score);
    printf("Best position: ");
    for (int i = 0; i < dimensions; i++) {
        printf("%f ", swarm->best_positions[best_index][i]);
    }
    printf("\n");

    destroy_swarm(swarm);
}