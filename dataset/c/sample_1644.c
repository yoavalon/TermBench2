#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIMENSIONS 30
#define SWARM_SIZE 50
#define COGNITIVE_FACTOR 0.7

void update_position(double *position, double *velocity, double *best_position, double *global_best) {
    for (int i = 0; i < DIMENSIONS; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive = r1 * (best_position[i] - position[i]);
        double social = r2 * (global_best[i] - position[i]);
        velocity[i] = COGNITIVE_FACTOR * velocity[i] + cognitive + social;
        position[i] = position[i] + velocity[i];
    }
}

void optimize() {
    double positions[SWARM_SIZE][DIMENSIONS];
    double velocities[SWARM_SIZE][DIMENSIONS];
    double best_positions[SWARM_SIZE][DIMENSIONS];
    double global_best[DIMENSIONS];

    for (int i = 0; i < SWARM_SIZE; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            positions[i][j] = (double)rand() / RAND_MAX;
            velocities[i][j] = (double)rand() / RAND_MAX;
            best_positions[i][j] = positions[i][j];
        }
    }

    double min_fitness = 0;
    for (int j = 0; j < DIMENSIONS; j++) {
        global_best[j] = best_positions[0][j];
        min_fitness += best_positions[0][j];
    }

    for (int i = 1; i < SWARM_SIZE; i++) {
        double fitness = 0;
        for (int j = 0; j < DIMENSIONS; j++) {
            fitness += best_positions[i][j];
        }
        if (fitness < min_fitness) {
            min_fitness = fitness;
            for (int j = 0; j < DIMENSIONS; j++) {
                global_best[j] = best_positions[i][j];
            }
        }
    }

    while (1) {
        for (int i = 0; i < SWARM_SIZE; i++) {
            update_position(positions[i], velocities[i], best_positions[i], global_best);
            double fitness = 0;
            for (int j = 0; j < DIMENSIONS; j++) {
                fitness += positions[i][j];
            }
            if (fitness < min_fitness) {
                for (int j = 0; j < DIMENSIONS; j++) {
                    best_positions[i][j] = positions[i][j];
                }
                min_fitness = fitness;
                for (int j = 0; j < DIMENSIONS; j++) {
                    global_best[j] = positions[i][j];
                }
            }
        }
    }
}

int main() {
    srand(time(0));
    optimize();
    return 0;
}