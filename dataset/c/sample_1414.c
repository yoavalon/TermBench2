#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10
#define DIMENSIONS 3

typedef struct {
    int size;
    int dimensions;
    double positions[SIZE][DIMENSIONS];
    double velocities[SIZE][DIMENSIONS];
    double best_positions[SIZE][DIMENSIONS];
    double best_score;
} Swarm;

typedef struct {
    Swarm *swarm;
} Environment;

void swarm_init(Swarm *swarm, int size, int dimensions) {
    swarm->size = size;
    swarm->dimensions = dimensions;
    swarm->best_score = INFINITY;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < dimensions; j++) {
            swarm->positions[i][j] = (double)rand() / RAND_MAX;
            swarm->velocities[i][j] = (double)rand() / RAND_MAX;
            swarm->best_positions[i][j] = swarm->positions[i][j];
        }
    }
}

void swarm_update_personal_best(Swarm *swarm, double score) {
    if (score < swarm->best_score) {
        swarm->best_score = score;
        for (int i = 0; i < swarm->size; i++) {
            for (int j = 0; j < swarm->dimensions; j++) {
                swarm->best_positions[i][j] = swarm->positions[i][j];
            }
        }
    }
}

void swarm_update_velocity(Swarm *swarm, double global_best[DIMENSIONS]) {
    double inertia = 0.5;
    double cognitive = 1.5;
    double social = 1.5;

    for (int i = 0; i < swarm->size; i++) {
        for (int j = 0; j < swarm->dimensions; j++) {
            double r1 = (double)rand() / RAND_MAX;
            double r2 = (double)rand() / RAND_MAX;
            swarm->velocities[i][j] = inertia * swarm->velocities[i][j] +
                                     cognitive * r1 * (swarm->best_positions[i][j] - swarm->positions[i][j]) +
                                     social * r2 * (global_best[j] - swarm->positions[i][j]);
        }
    }
}

void swarm_update_position(Swarm *swarm) {
    for (int i = 0; i < swarm->size; i++) {
        for (int j = 0; j < swarm->dimensions; j++) {
            swarm->positions[i][j] += swarm->velocities[i][j];
        }
    }
}

void environment_init(Environment *environment, Swarm *swarm) {
    environment->swarm = swarm;
}

double* environment_evaluate(Environment *environment) {
    static double scores[SIZE];
    for (int i = 0; i < environment->swarm->size; i++) {
        double score = 0.0;
        for (int j = 0; j < environment->swarm->dimensions; j++) {
            score += pow(environment->swarm->positions[i][j], 2);
        }
        scores[i] = score;
    }
    return scores;
}

void environment_find_global_best(Environment *environment, double *scores, double global_best[DIMENSIONS]) {
    int global_best_index = 0;
    for (int i = 1; i < environment->swarm->size; i++) {
        if (scores[i] < scores[global_best_index]) {
            global_best_index = i;
        }
    }
    for (int j = 0; j < environment->swarm->dimensions; j++) {
        global_best[j] = environment->swarm->positions[global_best_index][j];
    }
}

void main() {
    Swarm swarm;
    Environment environment;

    swarm_init(&swarm, SIZE, DIMENSIONS);
    environment_init(&environment, &swarm);

    int iterations = 50;
    for (int _ = 0; _ < iterations; _++) {
        double *scores = environment_evaluate(&environment);
        double global_best[DIMENSIONS];
        environment_find_global_best(&environment, scores, global_best);
        swarm_update_personal_best(&swarm, *scores);
        swarm_update_velocity(&swarm, global_best);
        swarm_update_position(&swarm);
    }
    printf("Best score: %f\n", swarm.best_score);
}

int main() {
    main();
    return 0;
}