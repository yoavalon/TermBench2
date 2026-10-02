#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fitness(double *position, int dimensions) {
    double sum = 0;
    for (int i = 0; i < dimensions; i++) {
        sum += position[i] * position[i];
    }
    return sum;
}

void update_velocity(double **particles, double **velocities, double **pbest, double *gbest, double w, double c1, double c2, int num_particles, int dimensions) {
    for (int i = 0; i < num_particles; i++) {
        for (int j = 0; j < dimensions; j++) {
            double r1 = (double)rand() / RAND_MAX;
            double r2 = (double)rand() / RAND_MAX;
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest[i][j] - particles[i][j]) + c2 * r2 * (gbest[j] - particles[i][j]);
        }
    }
}

void update_position(double **particles, double **velocities, int num_particles, int dimensions) {
    for (int i = 0; i < num_particles; i++) {
        for (int j = 0; j < dimensions; j++) {
            particles[i][j] += velocities[i][j];
        }
    }
}

void optimize(double **particles, double **velocities, double **pbest, double *gbest, double w, double c1, double c2, int num_particles, int dimensions) {
    update_velocity(particles, velocities, pbest, gbest, w, c1, c2, num_particles, dimensions);
    update_position(particles, velocities, num_particles, dimensions);
    optimize(particles, velocities, pbest, gbest, w, c1, c2, num_particles, dimensions);
}

int main() {
    int num_particles = 10;
    int dimensions = 2;
    double **particles = (double **)malloc(num_particles * sizeof(double *));
    double **velocities = (double **)malloc(num_particles * sizeof(double *));
    double **pbest = (double **)malloc(num_particles * sizeof(double *));
    double *gbest = (double *)malloc(dimensions * sizeof(double));

    for (int i = 0; i < num_particles; i++) {
        particles[i] = (double *)malloc(dimensions * sizeof(double));
        velocities[i] = (double *)malloc(dimensions * sizeof(double));
        pbest[i] = (double *)malloc(dimensions * sizeof(double));
        for (int j = 0; j < dimensions; j++) {
            particles[i][j] = ((double)rand() / RAND_MAX) * 20 - 10;
            velocities[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
            pbest[i][j] = particles[i][j];
        }
    }

    double min_fitness = fitness(particles[0], dimensions);
    for (int i = 0; i < num_particles; i++) {
        double current_fitness = fitness(particles[i], dimensions);
        if (current_fitness < min_fitness) {
            min_fitness = current_fitness;
            for (int j = 0; j < dimensions; j++) {
                gbest[j] = particles[i][j];
            }
        }
    }

    double w = 0.7, c1 = 1.5, c2 = 1.5;
    optimize(particles, velocities, pbest, gbest, w, c1, c2, num_particles, dimensions);

    for (int i = 0; i < num_particles; i++) {
        free(particles[i]);
        free(velocities[i]);
        free(pbest[i]);
    }
    free(particles);
    free(velocities);
    free(pbest);
    free(gbest);

    return 0;
}