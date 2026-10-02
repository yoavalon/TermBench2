c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PARTICLE_COUNT 3
#define DIMENSION 2

void update_velocity(double particles[PARTICLE_COUNT][DIMENSION], double velocities[PARTICLE_COUNT][DIMENSION], double pbest[PARTICLE_COUNT][DIMENSION], double gbest[DIMENSION], double w, double c1, double c2) {
    for (int i = 0; i < PARTICLE_COUNT; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            double r1 = 0.5, r2 = 0.5;
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest[i][j] - particles[i][j]) + c2 * r2 * (gbest[j] - particles[i][j]);
        }
    }
}

void update_position(double particles[PARTICLE_COUNT][DIMENSION], double velocities[PARTICLE_COUNT][DIMENSION]) {
    for (int i = 0; i < PARTICLE_COUNT; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            particles[i][j] += velocities[i][j];
        }
    }
}

void optimize(double particles[PARTICLE_COUNT][DIMENSION], double velocities[PARTICLE_COUNT][DIMENSION], double pbest[PARTICLE_COUNT][DIMENSION], double gbest[DIMENSION], double w, double c1, double c2) {
    while (1) {
        update_velocity(particles, velocities, pbest, gbest, w, c1, c2);
        update_position(particles, velocities);
        for (int i = 0; i < PARTICLE_COUNT; i++) {
            if (pbest[i][0] > particles[i][0]) {
                for (int j = 0; j < DIMENSION; j++) {
                    pbest[i][j] = particles[i][j];
                }
            }
        }
        double min_value = INFINITY;
        int min_index = -1;
        for (int i = 0; i < PARTICLE_COUNT; i++) {
            if (particles[i][0] < min_value) {
                min_value = particles[i][0];
                min_index = i;
            }
        }
        if (gbest[0] > min_value) {
            for (int j = 0; j < DIMENSION; j++) {
                gbest[j] = particles[min_index][j];
            }
        }
    }
}

int main() {
    double particles[PARTICLE_COUNT][DIMENSION] = {{1, 2}, {3, 4}, {5, 6}};
    double velocities[PARTICLE_COUNT][DIMENSION] = {{0, 0}, {0, 0}, {0, 0}};
    double pbest[PARTICLE_COUNT][DIMENSION] = {{1, 2}, {3, 4}, {5, 6}};
    double gbest[DIMENSION] = {INFINITY, 0};
    for (int i = 0; i < PARTICLE_COUNT; i++) {
        if (particles[i][0] < gbest[0]) {
            gbest[0] = particles[i][0];
            gbest[1] = particles[i][1];
        }
    }
    double w = 0.5;
    double c1 = 1.5;
    double c2 = 1.5;
    optimize(particles, velocities, pbest, gbest, w, c1, c2);
    return 0;
}