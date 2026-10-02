#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PARTICLES 30
#define DIMENSIONS 2
#define BOUNDS_MIN 0
#define BOUNDS_MAX 10

double random_uniform(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

double** initialize_particles(int num_particles, int dimensions, double bounds[2]) {
    double** particles = (double**)malloc(num_particles * sizeof(double*));
    for (int i = 0; i < num_particles; i++) {
        particles[i] = (double*)malloc(dimensions * sizeof(double));
        for (int j = 0; j < dimensions; j++) {
            particles[i][j] = random_uniform(bounds[0], bounds[1]);
        }
    }
    return particles;
}

double** update_positions(double** particles, double** velocities, double bounds[2], int num_particles, int dimensions) {
    double** new_positions = (double**)malloc(num_particles * sizeof(double*));
    for (int i = 0; i < num_particles; i++) {
        new_positions[i] = (double*)malloc(dimensions * sizeof(double));
        for (int j = 0; j < dimensions; j++) {
            new_positions[i][j] = fmax(bounds[0], fmin(bounds[1], particles[i][j] + velocities[i][j]));
        }
    }
    return new_positions;
}

int main() {
    srand(time(NULL));
    double bounds[2] = {BOUNDS_MIN, BOUNDS_MAX};
    double** particles = initialize_particles(NUM_PARTICLES, DIMENSIONS, bounds);
    double** velocities = (double**)malloc(NUM_PARTICLES * sizeof(double*));
    for (int i = 0; i < NUM_PARTICLES; i++) {
        velocities[i] = (double*)malloc(DIMENSIONS * sizeof(double));
        for (int j = 0; j < DIMENSIONS; j++) {
            velocities[i][j] = random_uniform(-1, 1);
        }
    }
    for (int t = 0; t < 100; t++) {
        for (int i = 0; i < NUM_PARTICLES; i++) {
            free(particles[i]);
        }
        free(particles);
        particles = update_positions(particles, velocities, bounds, NUM_PARTICLES, DIMENSIONS);
    }
    for (int i = 0; i < NUM_PARTICLES; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            printf("%f ", particles[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < NUM_PARTICLES; i++) {
        free(particles[i]);
        free(velocities[i]);
    }
    free(particles);
    free(velocities);
    return 0;
}